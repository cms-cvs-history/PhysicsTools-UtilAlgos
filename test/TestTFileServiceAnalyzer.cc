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
  TH1F * h_test1, * h_test2;
  /// sub-directory name
  std::string dir1_, dir2_;
};

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
using namespace edm;
using namespace std;

TestTFileServiceAnalyzer::TestTFileServiceAnalyzer( const ParameterSet & cfg ) :
  dir1_( cfg.getParameter<string>( "dir1" ) ),
  dir2_( cfg.getParameter<string>( "dir2" ) ) {
  Service<TFileService> fs;
  if ( ! dir1_.empty() )
    fs->cd( dir1_ );
  h_test1 = fs->make<TH1F>( "test1"  , "test histogram #1", 100,  0., 100. );
  if ( ! dir2_.empty() )
    fs->cd( dir2_ );
  h_test2 = fs->make<TH1F>( "test2"  , "test histogram #2", 100,  0., 100. );
}

void TestTFileServiceAnalyzer::analyze( const Event& evt, const EventSetup& ) {
  h_test1->Fill( 50. );
  h_test2->Fill( 60. );
}

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE( TestTFileServiceAnalyzer );
