//
//  XMLDictionary.swift
//  languageTest
//
//  Created by Vuk Knezevic on 3/28/17.
//  Copyright © 2017 Vuk Knezevic. All rights reserved.
//

import UIKit

enum XMLDictionaryAttributesMode : Int {
    case prefixed = 0 //default
    case dictionary
    case unprefixed
    case discard
}

enum XMLDictionaryNodeNameMode : Int {
    case rootOnly = 0 //default
    case always
    case never
}

let XMLDictionaryAttributesKey: NSString = "__attributes"
let XMLDictionaryCommentsKey: NSString = "__comments"
let XMLDictionaryTextKey: NSString = "__text"
let XMLDictionaryNodeNameKey: NSString = "__name"
let XMLDictionaryAttributePrefix: NSString = "_"


extension String {
    var xmlEncodedString: String {
        get {
            return self.replacingOccurrences(of: "&", with: "&amp;").replacingOccurrences(of: "<", with: "&lt;").replacingOccurrences(of: ">", with: "&gt;").replacingOccurrences(of: "\"", with: "&quot;").replacingOccurrences(of: "\'", with: "&apos;")
        }
    }
}


extension NSDictionary {
    func dictionaryWithXMLParser (parser: XMLParser) -> NSDictionary{
        return XMLDictionaryParser.sharedInstance.dictionaryWithParser(parser: parser)
    }
    
    func dictionaryWithXMLData (data: Data) -> NSDictionary {
        return XMLDictionaryParser.sharedInstance.dictionaryWithData(data: data)
    }
    
    func dictionaryWithXMLString (string: String) -> NSDictionary {
        return XMLDictionaryParser.sharedInstance.dictionaryWithString(string: string)
    }
    
    func dictionaryWithXMLFile (path: String) -> NSDictionary {
        return XMLDictionaryParser.sharedInstance.dictionaryWithFile(path: path)
    }
    
    var attributes: NSDictionary? {
        get {
            let attributesKey: NSDictionary? = self[XMLDictionaryAttributesKey] as? NSDictionary
            if (attributesKey != nil) {
                return attributesKey
            } else {
                let filteredDict: NSMutableDictionary? = self as? NSMutableDictionary
                filteredDict?.removeObjects(forKeys: [XMLDictionaryCommentsKey, XMLDictionaryTextKey, XMLDictionaryNodeNameKey])
                
                for key in (filteredDict?.allKeys)! {
                    filteredDict!.removeObject(forKey: key as! String)
                    if (key as! String).hasPrefix(XMLDictionaryAttributePrefix as String) {
                        filteredDict?[((key as! NSString).substring(from: XMLDictionaryAttributePrefix.length))] = (self)[key]
                    }
                }
                return filteredDict
            }
            //return nil
        }
    }
    
    var childNodes: NSDictionary? {
        get {
            let filteredDict: NSMutableDictionary? = self as? NSMutableDictionary
            filteredDict?.removeObjects(forKeys: [XMLDictionaryCommentsKey, XMLDictionaryTextKey, XMLDictionaryNodeNameKey])
            for key in (filteredDict?.allKeys)! {
                if (key as! String).hasPrefix(XMLDictionaryAttributePrefix as String) {
                    filteredDict!.removeObject(forKey: key as! String)
                }
            }
            return filteredDict
        }
    }
        
    var comments: [AnyObject]? {
        get {
            return self[XMLDictionaryCommentsKey] as? [AnyObject]
        }
    }
    
    var nodeName: String? {
        get {
            return self[XMLDictionaryNodeNameKey] as? String
        }
    }
    
    var innerText: String? {
        get {
            let text = self[XMLDictionaryTextKey]
            if text is NSArray {
                return (text as! NSArray).componentsJoined(by: "\n")
            } else {
                return text as! String?
            }
        }
    }
    
    var innerXML: String {
        get {
            var nodes = [String]()
            for comment in comments! {
                nodes.append("<!--\((comment as! String).xmlEncodedString)-->")
            }
            let childNodes: NSDictionary? = self.childNodes
            for (key,_) in childNodes! {
                nodes.append(XMLDictionaryParser.sharedInstance.XMLStringForNode(node: (childNodes![key])! as AnyObject, withNodeName: key as! String))
            }
            let text = self.innerText
            if text != nil {
                nodes.append(text!.xmlEncodedString)
            }
            return (nodes as NSArray).componentsJoined(by: "\n")
        }
    }
    
    var xmlString: String {
        get {
            if self.count == 1 && !(self.nodeName != nil) {
                return self.innerXML
            } else {
                return XMLDictionaryParser.sharedInstance.XMLStringForNode(node: self, withNodeName: nodeName ?? "root")
            }
        }
    }
    
    func arrayValue(forKeyPath keyPath: String) -> [Any]? {
        let value: Any? = self.value(forKeyPath: keyPath)
        if (value != nil) && !(value is [Any]) {
            return [value!]
        }
        return value as! [Any]?
    }
    
    func stringValue(forKeyPath keyPath: String) -> String? {
        var value: Any? = self.value(forKeyPath: keyPath)
        if (value is [Any]) {
            value = (value as? [Any])?.first
        }
        if (value is [AnyHashable: Any]) {
            return (value as! NSDictionary).innerText
        }
        return value as! String?
    }
    
    func dictionaryValue(forKeyPath keyPath: String) -> NSDictionary? {
        var value: Any? = self.value(forKeyPath: keyPath)
        if (value is [Any]) {
            value = (value as? [Any])?.first
        }
        if (value is String) {
            return [XMLDictionaryTextKey as String: value as AnyObject]
        }
        return value as! NSDictionary?
    }
}


class XMLDictionaryParser: NSObject, XMLParserDelegate {
    
    var root: NSDictionary? = nil
    var stack: [Any]? = nil
    var text: String? = nil
    
    static var sharedInstance = XMLDictionaryParser()
    private override init() {}
    
    var collapseTextNodes: Bool = true
    var stripEmptyNodes: Bool = true
    var trimWhiteSpace: Bool = true
    var alwaysUseArrays: Bool = false
    var preserveComments: Bool = false
    var wrapRootNode: Bool = false
    
    var attributesMode: XMLDictionaryAttributesMode = XMLDictionaryAttributesMode.prefixed
    var nodeNameMode: XMLDictionaryNodeNameMode = XMLDictionaryNodeNameMode.rootOnly
    
    func dictionaryWithParser(parser: XMLParser) -> NSDictionary {
        parser.delegate = self
        parser.parse()
        let result = root
        root = nil
        stack = nil
        text = nil
        return result!
    }
    
    func dictionaryWithData(data: Data) -> NSDictionary {
        let parser: XMLParser = XMLParser(data: data)
        return self.dictionaryWithParser(parser: parser)
    }
    
    func dictionaryWithString(string: String) -> NSDictionary {
        let data = string.data(using: String.Encoding.utf8)
        return self.dictionaryWithData(data: data!)
    }
    
    func dictionaryWithFile(path: String) -> NSDictionary {
        let data = try! Data(contentsOf: URL(fileURLWithPath: path))
        return dictionaryWithData(data: data)
    }
    
    func XMLStringForNode(node: AnyObject, withNodeName nodeName: String) -> String {
        if (node is [Any]) {
            let nodes = NSMutableArray.init(capacity: node.count)
            for individualNode in node as! [Any]{
                nodes.add(XMLStringForNode(node: individualNode as AnyObject, withNodeName: nodeName))
            }
            return (nodes as NSArray).componentsJoined(by: "\n")
        }
        else if (node is NSDictionary) {
            let attributes: NSDictionary? = (node as? NSDictionary)?.attributes as NSDictionary?
            let attributeString = NSMutableString()
            let count = 2
            let stride = MemoryLayout<ObjCBool>.stride
            let alignment = MemoryLayout<ObjCBool>.alignment
            let byteCount = stride * count
            let pointer = UnsafeMutableRawPointer.allocate(bytes: byteCount, alignedTo: alignment)
            attributes?.enumerateKeysAndObjects({ (key, value, pointer) in
                attributeString.appendFormat(" \((key as AnyObject).description.xmlEncodedString)=\"\((value as AnyObject).description.xmlEncodedString)\"" as NSString, pointer)
            })
            var innerXML: String = node.innerXML
            if (innerXML.characters.count > 0) {
                return String(format: "<%1$@%2$@>%3$@</%1$@>", nodeName, attributeString, innerXML)
            }
            else {
                return "<\(nodeName)\(attributeString)/>"
            }
        }
        else {
            return String(format: "<%1$@>%2$@</%1$@>", nodeName, node.description.xmlEncodedString)
        }
    }
    
    func endText() {
        if trimWhiteSpace {
            text = text?.trimmingCharacters(in: CharacterSet.whitespacesAndNewlines)
        }
        if text != nil {
            var top: [AnyHashable: Any]? = stack?.last as! [AnyHashable : Any]?
            let existing: Any? = top?[XMLDictionaryTextKey]
            if (existing is [Any]) {
                (existing as AnyObject).append(text!)
            }
            else if existing != nil {
                top?[XMLDictionaryTextKey] = [existing, text]
            }
            else {
                top?[XMLDictionaryTextKey] = text
            }
        }
        self.text = nil
    }
    
    func addText(text: String) {
        if self.text == nil {
            self.text = text
        } else {
            self.text?.appending(text)
        }
    }
    
    func parser(_ parser: XMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes attributeDict: [String : String] = [:]) {
        self.endText()
        var node: NSMutableDictionary = NSMutableDictionary()
        
        switch nodeNameMode {
        case .rootOnly:
            if self.root == nil {
                node[XMLDictionaryNodeNameKey as String] = elementName
            }
            break
        case .always:
            node[XMLDictionaryNodeNameKey as String] = elementName
            break
        case .never:
            break
        }
        
        if attributeDict.count > 0 {
            switch attributesMode {
            case .prefixed:
                for (key,_) in attributeDict {
                    node[XMLDictionaryAttributePrefix.appending(key)] = attributeDict[key]
                }
                break
            case .dictionary:
                node[XMLDictionaryAttributesKey as String] = attributeDict
                break
            case .unprefixed:
                //for (k, v) in attributeDict { node.updateValue(v, forKey: k) }
                node.addEntries(from: attributeDict)
                break
            case .discard:
                break
            }
        }
        
        if root == nil {
            self.root = node as NSDictionary?
            self.stack = [node]
            if wrapRootNode {
                self.root = NSMutableDictionary(object: root!, forKey: elementName as NSCopying)
            }
        } else {
            let top: NSMutableDictionary? = stack!.last as? NSMutableDictionary
            let existing: Any? = top![elementName]
            if existing is NSArray{
                (existing as! NSMutableArray).add(node)
            } else if existing != nil {
//                (top?[elementName] as! NSMutableArray).removeAllObjects()
//                (top?[elementName] as! NSMutableArray).add(existing!)
//                (top?[elementName] as! NSMutableArray).add(node)
                top?[elementName] = [existing, node]
                
            } else if alwaysUseArrays {
//                (top?[elementName] as! NSMutableArray).removeAllObjects()
//                (top?[elementName] as! NSMutableArray).add(node)
                top?[elementName] = NSMutableArray(object: node)
            } else {
//                (top?[elementName] as? NSMutableDictionary)?.removeAllObjects()
//                (top?[elementName] as? NSMutableDictionary)?.addEntries(from: node)
                top?[elementName] = node
            }
            stack?.append(node)
        }
    }
    
    func nameForNode(node: NSDictionary, inDictionary dict: NSDictionary) -> String? {
        if node.nodeName != nil {
         return node.nodeName!
        } else {
            for (name,_) in dict {
                let object: Any = dict[name as! String]!
                if object as! NSDictionary == node {
                    return name as? String
                } else if (object as! NSArray).contains(node) {
                    return name as? String
                }
            }
        }
        return nil
    }
    
    func parser(_ parser: XMLParser, didEndElement elementName: String, namespaceURI: String?, qualifiedName qName: String?) {
        self.endText()
        let top: NSMutableDictionary = stack?.last as! NSMutableDictionary
        stack?.removeLast()
        
        if top.attributes == nil && top.childNodes == nil && top.comments == nil {
            let newTop: NSMutableDictionary = stack?.last as! NSMutableDictionary
            let nodeName: String? = self.nameForNode(node: top, inDictionary: newTop)
            if nodeName != nil {
                let parentNode: AnyObject = newTop[nodeName!]! as AnyObject
                let innerText = top.innerText
                if innerText != nil && collapseTextNodes {
                    if parentNode is NSArray {
                        ((parentNode as! NSMutableArray)[(parentNode as! NSMutableArray).count - 1] as! NSMutableString).setString(innerText!)
                    } else {
                        newTop[nodeName!] = innerText
                    }
                } else if innerText == nil {
                    if stripEmptyNodes {
                        if parentNode is NSMutableArray {
                            (parentNode as! NSMutableArray).removeLastObject()
                        } else {
                            newTop.removeObject(forKey: nodeName!)
                        }
                    } else if !collapseTextNodes {
                        top[XMLDictionaryTextKey] = ""
                    }
                }
            }
        }
    }
    
    func parser(_ parser: XMLParser, foundCharacters string: String) {
        self.addText(text: string)
    }
    
    func parser(_ parser: XMLParser, foundCDATA CDATABlock: Data) {
        let string = NSString(data: CDATABlock, encoding: String.Encoding.utf8.rawValue)
        self.addText(text: string as! String)
    }
    
    func parser(_ parser: XMLParser, foundComment comment: String) {
        if preserveComments {
            let top: NSMutableDictionary = stack?.last as! NSMutableDictionary
            var comments: NSMutableArray? = top[XMLDictionaryCommentsKey] as? NSMutableArray
            if comments == nil {
                comments = [comment]
                top[XMLDictionaryCommentsKey] = comments
            } else {
                comments?.add(comment)
            }
        }
    }
    
}
