/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. 
The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. 
Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/


class Solution {
private:
    string validateIPv4(string IP) {
        int len = IP.length();
        int each = 0;
        int i = 0;
        if (IP[i] == '0')
            return "Neither";
        while (i < len) {
            each = 0;
            if (i > 0 and IP[i] == '0' and IP[i-1] == '.' and i+1 < len and IP[i+1] != '.')
                return "Neither";
            if (i > 0 and IP[i] == '.' and IP[i-1] == '.')
                return "Neither";
            if ((IP[i]-'0' > 9 or IP[i]-'0' < 0) and IP[i] != '.')
                return "Neither";
            while (IP[i] != '.' and i < len) {
                each = each * 10 + (IP[i]-'0');
                if (each > 255)
                    return "Neither";
                ++i;
            }
            if (each > 255)
                return "Neither";
            ++i;
        }
        return IP[i-1] == '.' ? "Neither" : "IPv4";
    }
    
    string validateIPv6(string IP) {
        int len = IP.length();
        int i = 0;
        string part = "";
        while (i < len) {
            if (IP[i] != ':' and (IP[i]-'0' > 9 or IP[i]-'0' < 0) and abs(IP[i]-'a') > 5 and (IP[i]-'A' > 5 or IP[i]-'A' < 0))
                return "Neither";
            if (i > 0 and IP[i] == ':' and IP[i-1] == ':')
                return "Neither";
            if (IP[i] == ':') {
                if (part.length() > 4)
                    return "Neither";
                part = "";
            }
            if (IP[i] != ':')
                part += IP[i];
            ++i;
        }
        if (IP[i-1] == ':')
            return "Neither";
        return part.length() < 5 ? "IPv6" : "Neither";
    }
    
public:
    string validIPAddress(string IP) {
        int dot_cnt = 0, col_cnt = 0;
        for (char ch : IP) {
            if (ch == '.') ++dot_cnt;
            else if (ch == ':') ++col_cnt;
        }
        if (dot_cnt == 3)
            return validateIPv4(IP);
        else if (col_cnt == 7)
            return validateIPv6(IP);
        return "Neither";
    }
};