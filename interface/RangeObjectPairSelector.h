#ifndef UtilAlgos_RangeObjectPairSelector_h
#define UtilAlgos_RangeObjectPairSelector_h
#include "PhysicsTools/Utilities/interface/RangeObjectPairSelector.h"
#include "PhysicsTools/UtilAlgos/interface/ParameterAdapter.h"

namespace reco {
  namespace modules {
    
    template<typename F>
    struct ParameterAdapter<RangeObjectPairSelector<F> > {
      static RangeObjectPairSelector<F> make( const edm::ParameterSet & cfg ) {
	return RangeObjectPairSelector<F>( cfg.template getParameter<double>( "rangeMin" ),
					   cfg.template getParameter<double>( "rangeMax" ),
					   reco::modules::make<F>( cfg )
					   );
      }
    };
    
  }
}



#endif
