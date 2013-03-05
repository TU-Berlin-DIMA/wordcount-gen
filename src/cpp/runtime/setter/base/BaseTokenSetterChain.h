// auto-generatad C++ setter chain for `token`

#ifndef BASETOKENSETTERCHAIN_H_
#define BASETOKENSETTERCHAIN_H_

#include "config/GeneratorConfig.h"
#include "runtime/setter/SetterChain.h"
#include "record/Token.h"
#include "record/TokenUtil.h"
#include "runtime/provider/value/RandomValueProvider.h"
#include "runtime/setter/FieldSetter.h"

namespace WordCountGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

/**
 * SetterChain specialization for User.
 */
class BaseTokenSetterChain : public Myriad::SetterChain<Token>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_value`
    typedef Myriad::RandomValueProvider< Enum, Token, Myriad::CombinedPrFunction<Enum>, 0 > ValueProvider01Type;
    typedef Myriad::FieldSetter< Token, Myriad::RecordTraits<Token>::VALUE, ValueProvider01Type > SetValueType;
    // runtime components for setter `set_separator`
    typedef Myriad::RandomValueProvider< Enum, Token, Myriad::CombinedPrFunction<Enum>, 0 > ValueProvider02Type;
    typedef Myriad::FieldSetter< Token, Myriad::RecordTraits<Token>::SEPARATOR, ValueProvider02Type > SetSeparatorType;

    BaseTokenSetterChain(Myriad::BaseSetterChain::OperationMode& opMode, Myriad::RandomStream& random, Myriad::GeneratorConfig& config) :
        Myriad::SetterChain<Token>(opMode, random),
        _sequenceCardinality(config.cardinality("token")),
        _valueProvider01(config.function< Myriad::CombinedPrFunction<Enum> >("Pr[lexicon.gutenberg]")),
        _setValue(_valueProvider01),
        _valueProvider02(config.function< Myriad::CombinedPrFunction<Enum> >("Pr[lexicon.separator]")),
        _setSeparator(_valueProvider02),
        _logger(Logger::get("token.setter.chain"))
    {
    }

    virtual ~BaseTokenSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Token> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseTokenSetterChain* me = const_cast<BaseTokenSetterChain*>(this);

        // apply setter chain
        me->_setValue(recordPtr, me->_random);
        me->_setSeparator(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Myriad::Interval<I64u> filter(const Myriad::EqualityPredicate<Token>& predicate)
    {
        Myriad::Interval<I64u> result(0, _sequenceCardinality);

        // explicitly mimic inverse setter logic for gen_id
        if (predicate.bound(Myriad::RecordTraits<Token>::GEN_ID))
        {
            const AutoPtr<Token>& valueHolder = predicate.valueHolder();
            result.intersect(Myriad::Interval<I64u>(valueHolder->genID(), valueHolder->genID()+1));
        }

        // apply inverse setter chain, setters are applied in the same order
        _setValue.filterRange(predicate, result);
        _setSeparator.filterRange(predicate, result);

        return result;
    }

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_value`
    ValueProvider01Type _valueProvider01;
    SetValueType _setValue;

    // runtime components for setter `set_separator`
    ValueProvider02Type _valueProvider02;
    SetSeparatorType _setSeparator;

    // Logger instance.
    Logger& _logger;
};

} // namespace WordCountGen

#endif /* BASETOKENSETTERCHAIN_H_ */
