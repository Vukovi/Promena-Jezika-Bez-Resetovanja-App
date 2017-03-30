//
//  ViewController.swift
//  languageTest
//
//  Created by Vuk Knezevic on 3/27/17.
//  Copyright © 2017 Vuk Knezevic. All rights reserved.
//

import UIKit
import Localize

class ViewController: UIViewController {
    
    var assetsManager = AssetsManager()
    @IBOutlet weak var label: UILabel!
    @IBOutlet weak var idiDugme: UIButton!
    @IBOutlet weak var jezikDugme: UIButton!
    @IBOutlet weak var label2: UILabel!
    
    var strXMLData:String = ""
    var currentElement:String = ""
    var passData:Bool=false
    var passName:Bool=false
    var parser = XMLParser()
    
    var fileDirectoryPath: String!
    var path2: String!
    
    var albanskiJSON: Any! = nil
    
    override func viewDidLoad() {
        super.viewDidLoad()

        //prvo pravim JSON fajl koji cu da cuvam
        
        albanskiJSON = assetsManager.getLanguage()
        
        
        //sad pravim folder gde cu da cuvam json fajl
        
        let paths = NSSearchPathForDirectoriesInDomains(FileManager.SearchPathDirectory.documentDirectory, FileManager.SearchPathDomainMask.userDomainMask, true) // Ovo su putanje do svih foldera u Dokumentima
        let documentDirectorPath:String = paths[0] // Ovim pravim putanju za nove fajlove u Dokumnet folderu
        fileDirectoryPath = documentDirectorPath + "/alb-en.json" //putanja do fajla u (USER/USER/Library....)
        path2 = Bundle.main.resourcePath! + "/alb2-en.json"// putanja do fajla u (USER/USER/Bundle...)
        
        
        //proverim da li postoji taj fajl
        
        var objcBool:ObjCBool = true
        let postojiLiFajl = FileManager.default.fileExists(atPath: fileDirectoryPath, isDirectory: &objcBool)
        if postojiLiFajl == false{
            do{
                let data = try JSONSerialization.data(withJSONObject: albanskiJSON, options: JSONSerialization.WritingOptions.prettyPrinted)
                try FileManager.default.createFile(atPath: fileDirectoryPath, contents: data, attributes: nil)
                //try FileManager.default.copyItem(atPath: fileDirectoryPath, toPath: filePathFromApp)
                try FileManager.default.createFile(atPath: path2, contents: data, attributes: nil)
            }catch{
                print("Fajl nije mogao da se napravi")
            }
        }
        
        let a = fileDirectoryPath
        let b = try! String(contentsOfFile: a!)
        print(b)
        
        let filePath = Bundle.main.path(forResource: "jezik-en", ofType: "xml")
        let xmlDict = NSDictionary().dictionaryWithXMLFile(path: filePath!)
        print(xmlDict)
        
    }
    
    
    @IBAction func idiKliknuto(_ sender: UIButton) {
        performSegue(withIdentifier: "idiNa", sender: nil)
    }
    
    
    @IBAction func promenaJezika(_ sender: UIButton) {
        let actionSheet = UIAlertController(title: nil, message: "promena jezika", preferredStyle: UIAlertControllerStyle.actionSheet)
        for language in Localize.availableLanguages() {
            let displayName = Localize.displayNameForLanguage(language)
            let languageAction = UIAlertAction(title: displayName, style: .default, handler: {
                (alert: UIAlertAction!) -> Void in
                Localize.update(language: language)
            })
            actionSheet.addAction(languageAction)
        }
        let cancelAction = UIAlertAction(title: "Cancel", style: UIAlertActionStyle.cancel, handler: {
            (alert: UIAlertAction) -> Void in
        })
        actionSheet.addAction(cancelAction)
        self.present(actionSheet, animated: true, completion: nil)
        //updateUI()
    }
    
    func updateUI() {
        label.text = "strings.Languages.Albanian".localize()//"app.update.language".localize()//"hello.world".localize()
        idiDugme.setTitle("strings.RZBPaymentOverviewTableViewCell.POTCDetails".localize(), for: UIControlState.normal)
    }
    
    
    func copyImagesToDocuments(){
        let documentsPath = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true).first!
        let fileManager = FileManager.default
        do{
            let docsPath = Bundle.main
            if fileManager.fileExists(atPath: documentsPath) {
                try FileManager.default.removeItem(atPath: documentsPath)
            }
            try fileManager.copyItem(atPath: docsPath.bundlePath, toPath: documentsPath)
        }catch{
            print("\n")
            print(error)
        }
    }
    
}

