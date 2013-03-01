// auto-generatad C++ file for `token`

#ifndef BASETOKENMETA_H_
#define BASETOKENMETA_H_

#include "record/AbstractRecord.h"

namespace WordCountGen {

// forward declarations
class Token;

class BaseTokenMeta : public Myriad::RecordMeta<Token>
{
public:

    BaseTokenMeta(const Myriad::EnumSetPool& enumSets) : 
        separator(enumSets.get("lexicon.separator").values()), value(enumSets.get("lexicon.gutenberg").values())
    {
    }

    // enum set refecences
    const vector<String>& separator;
    const vector<String>& value;
};

} // namespace WordCountGen

#endif /* BASETOKENMETA_H_ */
