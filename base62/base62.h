#include <string>
#include <stdexcept>
#include <cstring>
#include <algorithm>

const char BASE62_CHARS[62] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

static int BASE62_LOOKUP[256];
static bool lookup_initialized = false;

inline void init_base62_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE62_LOOKUP, -1, sizeof(BASE62_LOOKUP));
    for(int i = 0; i < 62; i++){
        BASE62_LOOKUP[(unsigned char)BASE62_CHARS[i]] = i;
    }
    lookup_initialized = true;
}

inline int is_base62(char c){
    init_base62_lookup();
    return BASE62_LOOKUP[(unsigned char)c];
}

inline std::string base62_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::string result;
	
	for(size_t i = 0; i < text.length(); i++){
        unsigned long long num = (unsigned char)text[i];
        
        if(num == 0){
            result += '0';
            continue;
        }
        
        std::string temp;
        while(num > 0){
            temp += BASE62_CHARS[num % 62];
            num /= 62;
        }
        std::reverse(temp.begin(), temp.end());
        
        if(i > 0) result += ' ';
        result += temp;
	}
	
	return result;
}

inline std::string base62_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    init_base62_lookup();
    
    std::string decoded_str;
    std::string current_num;
    
    for(size_t i = 0; i < encoded.length(); i++){
        if(encoded[i] == ' '){
            if(!current_num.empty()){
                unsigned long long value = 0;
                for(char c : current_num){
                    int digit = is_base62(c);
                    if(digit == -1){
                        throw std::runtime_error("Invalid base62 character");
                    }
                    value = value * 62 + digit;
                }
                decoded_str += (char)value;
                current_num.clear();
            }
        }else{
            current_num += encoded[i];
        }
    }
    
    if(!current_num.empty()){
        unsigned long long value = 0;
        for(char c : current_num){
            int digit = is_base62(c);
            if(digit == -1){
                throw std::runtime_error("Invalid base62 character");
            }
            value = value * 62 + digit;
        }
        decoded_str += (char)value;
    }

    return decoded_str;
}
