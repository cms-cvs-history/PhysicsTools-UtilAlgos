#ifndef UtilAlgos_MassMinSelector_h
#define UtilAlgos_MassMinSelector_h
#include "PhysicsTools/UtilAlgos/interface/ParameterAdapter.h"
#include "PhysicsTools/Utilities/interface/MassMinSelector.h"

namespace reco {
  namespace modules {
    
    template<>
    struct ParameterAdapter<MassMinSelector> {
      static MassMinSelector make( const edm::ParameterSet & cfg ) {
	return 
	  MassMinSelector( cfg.getParameter<double>( "massMin" ) );
      }
    };
    
  }
}

#endif