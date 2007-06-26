#ifndef UtilAlgos_DeltaPhiMinPairSelector_h
#define UtilAlgos_DeltaPhiMinPairSelector_h
#include "PhysicsTools/UtilAlgos/interface/ParameterAdapter.h"
#include "PhysicsTools/Utilities/interface/DeltaPhiMinPairSelector.h"

namespace reco {
  namespace modules {
    
    template<>
    struct ParameterAdapter<DeltaPhiMinPairSelector> {
      static DeltaPhiMinPairSelector make( const edm::ParameterSet & cfg ) {
	return DeltaPhiMinPairSelector( cfg.getParameter<double>( "deltaPhiMin" ) );
      }
    };

  }
}

#endif