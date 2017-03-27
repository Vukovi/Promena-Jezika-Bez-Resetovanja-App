//
//  AssetsManager.swift
//  HolosSDK
//
//  Created by Sasa Gajic on 3/17/17.
//  Copyright © 2017 NFInnova. All rights reserved.
//

import UIKit

public class AssetsManager {
    var nsDocumentDirectory: FileManager.SearchPathDirectory!
    var nsUserDomainMask: FileManager.SearchPathDomainMask!
    var paths:[String]?
    
    init(){
        nsDocumentDirectory = FileManager.SearchPathDirectory.documentDirectory
        nsUserDomainMask    = FileManager.SearchPathDomainMask.userDomainMask
        paths               = NSSearchPathForDirectoriesInDomains(self.nsDocumentDirectory, nsUserDomainMask, true)
    }
    
    public func getImageForName(imageName: String) -> UIImage?{
        var imageName = imageName
        if let dirPath          = paths?.first
        {
            //if there is no . (extension) we will add png
            if imageName.range(of:".") != nil{
                imageName = imageName + ".png"
            }
            
            let imageURL = URL(fileURLWithPath: dirPath).appendingPathComponent("images/" + imageName)
            return UIImage(contentsOfFile: imageURL.path)
        }
        return nil
    }
    
    public func getLanguage() -> Any?{
        let languageURL = Bundle.main.path(forResource: "values", ofType: "txt")//"sr-Latn-CS"  "sq-AL"
        let languageStringFromTxt  = try! String(contentsOfFile: languageURL!)
        let languageString = languageStringFromTxt.replacingOccurrences(of: ",\r\n\t\t\t\t\t\t", with: "").replacingOccurrences(of: "%@", with: "").replacingOccurrences(of: "\" . \\n", with: "").replacingOccurrences(of: "\r\n\t", with: "").replacingOccurrences(of: "\t", with: "").replacingOccurrences(of: "\r\n                        ", with: "").replacingOccurrences(of: "\\n\\n", with: "").replacingOccurrences(of: "\\n", with: "")
        let languageData = languageString.data(using: String.Encoding.utf8)
        do {
            let json = try JSONSerialization.jsonObject(with: languageData!, options: JSONSerialization.ReadingOptions.mutableContainers)
            return json
        } catch let error as NSError {
            print(error.debugDescription)
        }
        return nil
    }
    
}
