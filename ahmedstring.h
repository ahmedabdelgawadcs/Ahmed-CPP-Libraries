#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ahmed {
	string replace_word(string str, string original_word, string word_to_replace) {
		short pos;

		while ((pos = str.find(original_word)) != string::npos)
			str.replace(pos, original_word.length(), word_to_replace);

		return str;
	}

	vector<string> split_str(string str, string delim = " ") {
		vector<string> vWords;
		string word;
		short pos;

		while ((pos = str.find(delim)) != string::npos) {
			word = str.substr(0, pos);

			if (word != "")
				vWords.push_back(word);

			str.erase(0, pos + delim.length());
		}

		if (str != "")
			vWords.push_back(str);

		return vWords;
	}

	string join_string(vector<string>& vWords, string delim = " ") {
		string str;

		for (string& n : vWords)
			str += n + delim;

		return str.substr(0, str.length() - delim.length());
	}
}