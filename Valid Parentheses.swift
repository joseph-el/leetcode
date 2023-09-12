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
