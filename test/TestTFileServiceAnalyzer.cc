#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "TH1.h"
class TestTFileServiceAnalyzer : public edm::EDAnalyzer {
public:
  /// constructor
  TestTFileServiceAnalyzer( const edm::ParameterSet & );

private:
  /// process one event
  void analyze( const edm::Event& , const edm::EventSetup& );
  /// histograms
  TH1F * h_test;
  /// sub-directory name
  std::string dir_;
};

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
using namespace edm;
using namespace std;

TestTFileServiceAnalyzer::TestTFileServiceAnalyzer( const ParameterSet & cfg ) :
  dir_( cfg.getParameter<string>( "dir" ) ) {
  Service<TFileService> fs;
  if ( ! dir_.empty() )
    fs->cd( dir_ );
  h_test = fs->make<TH1F>( "test"  , "test histogram", 100,  0., 100. );
}

void TestTFileServiceAnalyzer::analyze( const Event& evt, const EventSetup& ) {
  h_test->Fill( 50. );
}

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE( TestTFileServiceAnalyzer );
