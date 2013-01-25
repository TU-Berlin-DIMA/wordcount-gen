// auto-generatad C++ file for `token`

#ifndef BASETOKENMETA_H_
#define BASETOKENMETA_H_

#include "record/Record.h"

using namespace Myriad;

namespace WordCountGen {

// forward declarations
class Token;

class BaseTokenMeta : public RecordMeta<Token>
{
public:

    BaseTokenMeta(const EnumSetPool& enumSets) : 
        separator(enumSets.get("lexicon.separator").values()), value(enumSets.get("lexicon.gutenberg").values())
    {
    }

    // enum set refecences
    const vector<String>& separator;
    const vector<String>& value;
};

} // namespace WordCountGen

#endif /* BASETOKENMETA_H_ */
