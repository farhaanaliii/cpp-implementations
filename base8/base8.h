#include <string>
#include <bitset>
#include <stdexcept>
#include <cstring>

const char BASE8_CHARS[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};

static int BASE8_LOOKUP[256];
static bool lookup_initialized = false;

void init_base8_lookup(){
    if(lookup_initialized) return;
    
    std::memset(BASE8_LOOKUP, -1, sizeof(BASE8_LOOKUP));
    for(int i = 0; i < 8; i++){
        BASE8_LOOKUP[(unsigned char)BASE8_CHARS[i]] = i;
    }
    lookup_initialized = true;
}

int is_base8(char c){
    init_base8_lookup();
    return BASE8_LOOKUP[(unsigned char)c];
}

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

std::string base8_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::string bin_str;
	bin_str.reserve(text.length() * 8);
	
	for(size_t i = 0; i < text.length(); i++){
        std::string bits = std::bitset<8>((unsigned char)text[i]).to_string();
		bin_str += bits;
	}
	
    std::string base8_str;
    base8_str.reserve((bin_str.length() + 2) / 3);
    
    for(size_t i = 0; i < bin_str.length(); i += 3){
        std::string s3 = bin_str.substr(i, 3);
        s3 = str_pad(s3, 3, '0', 0);
        base8_str += BASE8_CHARS[stoi(s3, nullptr, 2)];
    }

	return base8_str;
}

std::string base8_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    init_base8_lookup();
    
    std::string bits_str;
    bits_str.reserve(encoded.length() * 3);
    
    for(size_t i = 0; i < encoded.length(); i++){
        int index = is_base8(encoded[i]);
        if(index == -1){
            throw std::runtime_error("Invalid base8 character");
        }

        std::string bits = std::bitset<3>(index).to_string();
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
