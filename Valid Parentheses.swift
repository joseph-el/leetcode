import SwiftUI



// '(', ')', '{', '}', '[' and ']'

class Solution {

func isValid(_ s: String) -> Bool {

    var set_ = (0, 0)

    for index in s {
        switch index {
            case "(", "{", "[" :
                set_.0 += 1
            case ")", "}" , "]" :
                set_.1 += 1
            default :
                return false
        }

    }

    set_.0 += set_.1


    return set_.0 % 2 == 0
}


}

var ret:Solution = Solution()

print("\(ret.isValid("(]"))")
    // func isValid(_ s: String) -> Bool {
    //     var para = (0 , 0)
    //     var coma = (0 , 0)
    //     var whoO = (0 , 0)
    //     var index = 0

    //     while index < s.count {

    //     let currentChar = s[s.index(s.startIndex, offsetBy: index)]

    //         // print ("the current \(currentChar)")
    //         switch currentChar {
    //             case "(" :
    //                 para.0 += 1
    //             case "{" :
    //                 coma.0 += 1
    //             case "[" :
    //                 whoO.0 += 1

    //             case ")" :
    //                 if s[s.index(s.startIndex, offsetBy: index - 1)] != "(" {
    //                     // print("iam here")
    //                     return false
    //                 }
    //                 para.1 += 1

    //             case "}" :
    //                 if s[s.index(s.startIndex, offsetBy: index - 1)] != "{" {
    //                     return false
    //                 }
    //                 coma.1 += 1
    //             case "]" :
    //                if s[s.index(s.startIndex, offsetBy: index - 1)] != "[" {
    //                     return false
    //                 }
    //                 whoO.1 += 1
    //             default :
    //                 return false
    //         }
    //         index += 1
    //     }

    //     para.0 += para.1
    //     coma.0 += coma.1
    //     whoO.0 += whoO.1

    //     // print("check > \(para.self)")
    //     // print("check > \(coma.self)")
    //     // print("check > \(whoO.self)")
    //     return para.0 % 2 == 0 &&  coma.0 % 2 == 0 && whoO.0 % 2 == 0
    // }








