//
//  SecondViewController.swift
//  languageTest
//
//  Created by Vuk Knezevic on 3/27/17.
//  Copyright © 2017 Vuk Knezevic. All rights reserved.
//

import UIKit
import Localize

class SecondViewController: UIViewController {

    @IBOutlet weak var label: UILabel!
    @IBOutlet weak var dugme: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()

//        dugme.setTitle("strings.NavigationBar.Cancel".localize(), for: UIControlState.normal)
//        label.text = "strings.Dashboard.DBAmountToSpend".localize()
    }

    @IBAction func vracanje(_ sender: UIButton) {
        dismiss(animated: true, completion: nil)
    }


}
