#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <algorithm>

const char BASE58_CHARS[58] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

static int BASE58_LOOKUP[256];
static bool lookup_initialized = false;

void init_base58_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE58_LOOKUP, -1, sizeof(BASE58_LOOKUP));
    for(int i = 0; i < 58; i++){
        BASE58_LOOKUP[(unsigned char)BASE58_CHARS[i]] = i;
    }
    lookup_initialized = true;
}

int is_base58(char c){
    init_base58_lookup();
    return BASE58_LOOKUP[(unsigned char)c];
}

std::string base58_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::vector<unsigned char> digits;
	
	for(size_t i = 0; i < text.length(); i++){
        unsigned int carry = (unsigned char)text[i];
        
        for(size_t j = 0; j < digits.size(); j++){
            carry += digits[j] << 8;
            digits[j] = carry % 58;
            carry /= 58;
        }
        
        while(carry > 0){
            digits.push_back(carry % 58);
            carry /= 58;
        }
	}
	
	std::string result;
	for(size_t i = 0; i < text.length() && text[i] == 0; i++){
        result += BASE58_CHARS[0];
	}
	
	for(auto it = digits.rbegin(); it != digits.rend(); ++it){
        result += BASE58_CHARS[*it];
	}
	
	return result.empty() ? std::string(1, BASE58_CHARS[0]) : result;
}

std::string base58_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    init_base58_lookup();
    
    std::vector<unsigned char> bytes;
    
    for(size_t i = 0; i < encoded.length(); i++){
        int digit = is_base58(encoded[i]);
        if(digit == -1){
            throw std::runtime_error("Invalid base58 character");
        }
        
        unsigned int carry = digit;
        
        for(size_t j = 0; j < bytes.size(); j++){
            carry += bytes[j] * 58;
            bytes[j] = carry & 0xFF;
            carry >>= 8;
        }
        
        while(carry > 0){
            bytes.push_back(carry & 0xFF);
            carry >>= 8;
        }
    }
    
    std::string result;
    for(size_t i = 0; i < encoded.length() && encoded[i] == BASE58_CHARS[0]; i++){
        result += '\0';
    }
    
    for(auto it = bytes.rbegin(); it != bytes.rend(); ++it){
        result += (char)*it;
    }

    return result;
}
