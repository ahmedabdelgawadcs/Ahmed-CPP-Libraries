#pragma once		// compiler directive

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

namespace ahmed {

	void print_file_content(string file_name) {
		fstream file;

		file.open(file_name, ios::in);	// read mode

		if (file.is_open()) {
			string line;

			while (getline(file, line))
				cout << line << endl;
		}

		file.close();
	}

	void load_file_to_v(string file_name, vector<string>& v) {
		fstream file;

		file.open(file_name, ios::in);	// read mode

		if (file.is_open()) {
			string line;

			while (getline(file, line))
				v.push_back(line);

		}

		file.close();
	}

	void save_v_in_file(string file_name, vector<string>& vContent) {
		fstream file;

		file.open(file_name, ios::out); // write mode

		if (file.is_open())
			for (string& line : vContent)
				if (line != "")
					file << line << endl;

		file.close();
	}

	void delete_rec_from_file(string file_name, string record) {
		vector<string> vFile_content;

		load_file_to_v(file_name, vFile_content);

		for (string& line : vFile_content)
			if (line == record)
				line = "";

		save_v_in_file(file_name, vFile_content);
	}

	void update_record_in_file(string file_name, string record, string update) {
		vector<string> vFile_content;

		load_file_to_v(file_name, vFile_content);

		for (string& line : vFile_content)
			if (line == record)
				line = update;

		save_v_in_file(file_name, vFile_content);
	}
}