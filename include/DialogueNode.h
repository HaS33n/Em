#pragma once
#include <string>
#include <map>
#include <iostream>
#include <fstream>

class DialogueNode
{
public:
	DialogueNode() { isFunctionNode = false; }
	//DialogueNode(std::string txt, std::string cText, std::string cCommand, unsigned short int tId) { text = txt; choicemap[std::make_pair(cText, cCommand)] = tId; }
	~DialogueNode() {};

	std::string text;
	std::map<std::pair<std::string, std::string>, unsigned short int> choicemap;

	bool isFunctionNode;
	std::string fName;
private:

};

