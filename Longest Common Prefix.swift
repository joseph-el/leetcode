
import SwiftUI

// class Solution {

    func GetPrifix(string1: String , string2: String) -> String {
        
    var boolean: [Bool] =  Array(repeating: false , count: string1.count)
    var prefix_:String? = nil
    var ind : String.Index

        while ind != string1.endIndex && ind != string2.endIndex {
            if string1[ind] != string2[ind] {
                boolean.append(false)
            } else {
                boolean.append(true)
            }
        }

        for index in boolean.indices {
            guard boolean[index] != true else {
                prefix_! += string1
            } 
        }

        return prefix_!
    }
    

    var test:String = GetPrifix(string1: "HJKjKJELOPOPOP",string2 : "BHBHBHELOZZZZZ")

    // func longestCommonPrefix(_ strs: [String]) -> String {
        
    //     var check:Bool = false
    //     var result:String? = nil

    
    //     // var Prefix:String? = 



    //     return String("  s(- _ -)s  ")
    // }
// }
