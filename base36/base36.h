#include <string>
#include <stdexcept>
#include <cstring>
#include <algorithm>

const char BASE36_CHARS[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

static int BASE36_LOOKUP[256];
static bool lookup_initialized = false;

void init_base36_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE36_LOOKUP, -1, sizeof(BASE36_LOOKUP));
    for(int i = 0; i < 36; i++){
        BASE36_LOOKUP[(unsigned char)BASE36_CHARS[i]] = i;
        if(BASE36_CHARS[i] >= 'A' && BASE36_CHARS[i] <= 'Z'){
            BASE36_LOOKUP[(unsigned char)(BASE36_CHARS[i] + 32)] = i;
        }
    }
    lookup_initialized = true;
}

int is_base36(char c){
    init_base36_lookup();
    return BASE36_LOOKUP[(unsigned char)c];
}

std::string base36_encode(const std::string &text){
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
            temp += BASE36_CHARS[num % 36];
            num /= 36;
        }
        std::reverse(temp.begin(), temp.end());
        
        if(i > 0) result += ' ';
        result += temp;
	}
	
	return result;
}

std::string base36_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    init_base36_lookup();
    
    std::string decoded_str;
    std::string current_num;
    
    for(size_t i = 0; i < encoded.length(); i++){
        if(encoded[i] == ' '){
            if(!current_num.empty()){
                unsigned long long value = 0;
                for(char c : current_num){
                    int digit = is_base36(c);
                    if(digit == -1){
                        throw std::runtime_error("Invalid base36 character");
                    }
                    value = value * 36 + digit;
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
            int digit = is_base36(c);
            if(digit == -1){
                throw std::runtime_error("Invalid base36 character");
            }
            value = value * 36 + digit;
        }
        decoded_str += (char)value;
    }

    return decoded_str;
}
