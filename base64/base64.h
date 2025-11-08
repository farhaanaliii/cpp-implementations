#include <string>
#include <bitset>
#include <stdexcept>
#include <cstring>

const char BASE64_CHARS[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

// Lookup table for O(1) character to index conversion
static int BASE64_LOOKUP[256];
static bool lookup_initialized = false;

void init_base64_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE64_LOOKUP, -1, sizeof(BASE64_LOOKUP));
    for(int i = 0; i < 64; i++){
        BASE64_LOOKUP[(unsigned char)BASE64_CHARS[i]] = i;
    }
    lookup_initialized = true;
}

int is_base64(char c){
    init_base64_lookup();
    return BASE64_LOOKUP[(unsigned char)c];
}

// direction: 1 => left
// direction: 0 => right
std::string str_pad(const std::string &str, int pad_len, char pad_char, int direction){
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


std::string base64_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::string bin_str;
	bin_str.reserve(text.length() * 8);
	
	for(size_t i = 0; i < text.length(); i++){
        std::string bits = std::bitset<8>((unsigned char)text[i]).to_string();
		bin_str += bits;
	}
	
    size_t encoded_len = (bin_str.length() + 5) / 6;
    std::string base64_str;
    base64_str.reserve(encoded_len + (4 - encoded_len % 4) % 4);
    
    for(size_t i = 0; i < bin_str.length(); i += 6){
        std::string s6 = bin_str.substr(i, 6);
        s6 = str_pad(s6, 6, '0', 0);
        base64_str += BASE64_CHARS[stoi(s6, nullptr, 2)];
    }

    if(base64_str.length() % 4 != 0){
        int gap = 4 - (base64_str.length() % 4);
        base64_str.append(gap, '=');
    }

	return base64_str;
}

std::string base64_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    init_base64_lookup();
    
    std::string bits_str;
    bits_str.reserve(encoded.length() * 6);
    
    for(size_t i = 0; i < encoded.length(); i++){
        if(encoded[i] == '=') continue;

        int index = is_base64(encoded[i]);
        if(index == -1){
            throw std::runtime_error("Invalid base64 character");
        }

        std::string bits = std::bitset<6>(index).to_string();
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
