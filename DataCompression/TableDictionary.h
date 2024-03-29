#pragma once

#include "Dictionary.h"
#include <string>

class TableDictionary final : public Dictionary
{
public:
	TableDictionary(uint8_t entryBitSize, uint8_t outputBitSize, bool listOverflow);
	~TableDictionary();

	bool getIndex(std::vector<uint16_t>& word, uint32_t& index, uint8_t& bitsNumber) override;

	uint32_t insertEntry(std::vector<uint16_t>& word) override;
	bool getEntry(uint32_t index, std::vector<uint16_t>& word) override;

	void flush() override;
	uint32_t removeElementFromList(std::basic_string<char16_t>) override;
	void insertElementToList(uint32_t currenIndex) override;

private:
	void initializeAlphabet() override;

	std::vector<std::basic_string<char16_t> > _container;
};

