#include <string>
#include <bitset>
#include <stdexcept>
#include <cstring>

const char BASE32_CHARS[32] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '2', '3', '4', '5', '6', '7'};

// Lookup table for O(1) character to index conversion
static int BASE32_LOOKUP[256];
static bool lookup_initialized = false;

inline void init_base32_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE32_LOOKUP, -1, sizeof(BASE32_LOOKUP));
    for(int i = 0; i < 32; i++){
        BASE32_LOOKUP[(unsigned char)BASE32_CHARS[i]] = i;
    }
    lookup_initialized = true;
}

inline int is_base32(char c){
    init_base32_lookup();
    return BASE32_LOOKUP[(unsigned char)c];
}

// direction: 1 => left
// direction: 0 => right
inline std::string str_pad(const std::string &str, int pad_len, char pad_char, int direction){
	if(str.length() >= pad_len){
		return str;
	}
	
	std::string _str;
	_str.reserve(pad_len);
	
	int padding = pad_len - str.length();
	
	if(direction == 1){
		_str.append(padding, pad_char);
		_str.append(str);
	}else{
		_str.append(str);
		_str.append(padding, pad_char);
	}
	
	return _str;
}


inline std::string base32_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::string bin_str;
	bin_str.reserve(text.length() * 8);
	
	for(size_t i = 0; i < text.length(); i++){
        std::string bits = std::bitset<8>((unsigned char)text[i]).to_string();
		bin_str += bits;
	}
	
    size_t encoded_len = (bin_str.length() + 4) / 5;
    std::string base32_str;
    base32_str.reserve(encoded_len + (8 - encoded_len % 8) % 8);
    
    for(size_t i = 0; i < bin_str.length(); i += 5){
        std::string s5 = bin_str.substr(i, 5);
        s5 = str_pad(s5, 5, '0', 0);
        base32_str += BASE32_CHARS[stoi(s5, nullptr, 2)];
    }

    if(base32_str.length() % 8 != 0){
        int gap = 8 - (base32_str.length() % 8);
        base32_str.append(gap, '=');
    }

	return base32_str;
}

inline std::string base32_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    init_base32_lookup();
    
    std::string bits_str;
    bits_str.reserve(encoded.length() * 5);
    
    for(size_t i = 0; i < encoded.length(); i++){
        if(encoded[i] == '=') continue;

        int index = is_base32(encoded[i]);
        if(index == -1){
            throw std::runtime_error("Invalid base32 character");
        }

        std::string bits = std::bitset<5>(index).to_string();
        bits_str += bits;
    }

    std::string decoded_str;
    decoded_str.reserve(bits_str.length() / 8);
    
    for(size_t i = 0; i < bits_str.length(); i += 8){
        if(i + 8 > bits_str.length()) break;
        std::string s8 = bits_str.substr(i, 8);
        decoded_str += (char)stoi(s8, nullptr, 2);
    }

    return decoded_str;
}
