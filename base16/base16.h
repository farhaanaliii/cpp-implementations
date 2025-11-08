#include <string>
#include <bitset>
#include <stdexcept>
#include <cstring>

const char BASE16_CHARS[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

static int BASE16_LOOKUP[256];
static bool lookup_initialized = false;

inline void init_base16_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE16_LOOKUP, -1, sizeof(BASE16_LOOKUP));
    for(int i = 0; i < 16; i++){
        BASE16_LOOKUP[(unsigned char)BASE16_CHARS[i]] = i;
        if(BASE16_CHARS[i] >= 'A' && BASE16_CHARS[i] <= 'F'){
            BASE16_LOOKUP[(unsigned char)(BASE16_CHARS[i] + 32)] = i;
        }
    }
    lookup_initialized = true;
}

inline int is_base16(char c){
    init_base16_lookup();
    return BASE16_LOOKUP[(unsigned char)c];
}

inline std::string base16_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::string hex_str;
	hex_str.reserve(text.length() * 2);
	
	for(size_t i = 0; i < text.length(); i++){
        unsigned char byte = (unsigned char)text[i];
        hex_str += BASE16_CHARS[byte >> 4];
        hex_str += BASE16_CHARS[byte & 0x0F];
	}
	
	return hex_str;
}

inline std::string base16_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    if(encoded.length() % 2 != 0){
        throw std::runtime_error("Invalid base16 length");
    }
    
    init_base16_lookup();
    
    std::string decoded_str;
    decoded_str.reserve(encoded.length() / 2);
    
    for(size_t i = 0; i < encoded.length(); i += 2){
        int high = is_base16(encoded[i]);
        int low = is_base16(encoded[i + 1]);
        
        if(high == -1 || low == -1){
            throw std::runtime_error("Invalid base16 character");
        }
        
        decoded_str += (char)((high << 4) | low);
    }

    return decoded_str;
}
