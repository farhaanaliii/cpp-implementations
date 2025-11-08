#include <string>
#include <stdexcept>
#include <cstring>

const char BASE85_CHARS[85] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'};

static int BASE85_LOOKUP[256];
static bool lookup_initialized = false;

void init_base85_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE85_LOOKUP, -1, sizeof(BASE85_LOOKUP));
    for(int i = 0; i < 85; i++){
        BASE85_LOOKUP[(unsigned char)BASE85_CHARS[i]] = i;
    }
    lookup_initialized = true;
}

int is_base85(char c){
    init_base85_lookup();
    return BASE85_LOOKUP[(unsigned char)c];
}

std::string base85_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::string result = "<~";
	
	for(size_t i = 0; i < text.length(); i += 4){
        unsigned long value = 0;
        int count = 0;
        
        for(int j = 0; j < 4 && i + j < text.length(); j++){
            value = (value << 8) | (unsigned char)text[i + j];
            count++;
        }
        
        if(count < 4){
            value <<= (8 * (4 - count));
        }
        
        if(value == 0 && count == 4){
            result += 'z';
        }else{
            char encoded[5];
            for(int j = 4; j >= 0; j--){
                encoded[j] = BASE85_CHARS[value % 85];
                value /= 85;
            }
            
            int output_len = count + 1;
            for(int j = 0; j < output_len; j++){
                result += encoded[j];
            }
        }
	}
	
	result += "~>";
	return result;
}

std::string base85_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    init_base85_lookup();
    
    std::string input = encoded;
    if(input.substr(0, 2) == "<~"){
        input = input.substr(2);
    }
    if(input.length() >= 2 && input.substr(input.length() - 2) == "~>"){
        input = input.substr(0, input.length() - 2);
    }
    
    std::string result;
    
    for(size_t i = 0; i < input.length();){
        if(input[i] == 'z'){
            result += "\0\0\0\0";
            i++;
            continue;
        }
        
        unsigned long value = 0;
        int count = 0;
        
        for(int j = 0; j < 5 && i < input.length() && input[i] != 'z'; j++, i++){
            int digit = is_base85(input[i]);
            if(digit == -1){
                throw std::runtime_error("Invalid base85 character");
            }
            value = value * 85 + digit;
            count++;
        }
        
        int output_bytes = count > 0 ? count - 1 : 0;
        
        for(int j = 3; j >= 0 && j >= 4 - output_bytes; j--){
            result += (char)((value >> (j * 8)) & 0xFF);
        }
    }

    return result;
}
