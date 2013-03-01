// auto-generatad base generator config C++ file

#ifndef BASEGENERATORCONFIG_H_
#define BASEGENERATORCONFIG_H_

#include "config/AbstractGeneratorConfig.h"

namespace Myriad {

class BaseGeneratorConfig: public AbstractGeneratorConfig
{
public:

    BaseGeneratorConfig(GeneratorPool& generatorPool) : AbstractGeneratorConfig(generatorPool)
    {
    }

protected:

    virtual void configurePartitioning()
    {
        // TODO: this piece of auto-generating code / Config API needs to be rewritten

        // setup linear scale estimator for token
        setString("partitioning.token.base-cardinality", toString<I64u>(parameter<I64u>("token.sequence.base_cardinality")));
        computeLinearScalePartitioning("token");
    }

    virtual void configureFunctions()
    {
        // register prototype functions
        function(new Myriad::CombinedPrFunction<Enum>("Pr[lexicon.gutenberg]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/lexicon/gutenberg.en.distribution")));
        function(new Myriad::CombinedPrFunction<Enum>("Pr[lexicon.separator]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/lexicon/separator.distribution")));
    }

    virtual void configureSets()
    {
        // bind string sets to config members with the bindStringSet method
        enumSet(new MyriadEnumSet("lexicon.separator", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/lexicon/separator.domain")));
        enumSet(new MyriadEnumSet("lexicon.gutenberg", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/lexicon/gutenberg.en.domain")));
    }
};

} // namespace Myriad

#endif /* BASEGENERATORCONFIG_H_ */
