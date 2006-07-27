// $Id: testmethods.cc,v 1.1 2006/07/27 14:20:38 llista Exp $
#include <cppunit/extensions/HelperMacros.h>
#include "PhysicsTools/UtilAlgos/interface/methods.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include <Reflex/Object.h>
#include <iostream>

class testMethods : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(testMethods);
  CPPUNIT_TEST(checkAll);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() {}
  void tearDown() {}
  void checkAll(); 
};

CPPUNIT_TEST_SUITE_REGISTRATION(testMethods);

void testMethods::checkAll() {
  using namespace ROOT::Reflex;
  using namespace reco::methods;
  const methodMap & m = methods<reco::Track>();
  printMethods<reco::Track>( std::cerr );

  double chi2 = 1.234;
  double ndof = 2.345;
  double pt = 10.0;
  math::Vector<5>::type par( 1.0, 2.0, 3.0, 4.0, 5.0 );
  math::Error<5>::type err;
  reco::Track trk( chi2, ndof, par, pt, err );
  Type trackType = Type::ByTypeInfo( typeid( reco::Track ) );
  Object trko( trackType, & trk );

  {
    methodMap::const_iterator f = m.find( "pt" );
    CPPUNIT_ASSERT( f != m.end() );
    Object ret = f->second.first.Invoke( trko );
    CPPUNIT_ASSERT( f->second.second == reco::methods::doubleType );
    double * val = static_cast<double *>( ret.Address() );
    CPPUNIT_ASSERT( * val == pt );
  }
  {
    methodMap::const_iterator f = m.find( "chi2" );
    CPPUNIT_ASSERT( f != m.end() );
    Object ret = f->second.first.Invoke( trko );
    CPPUNIT_ASSERT( f->second.second == reco::methods::doubleType );
    double * val = static_cast<double *>( ret.Address() );
    CPPUNIT_ASSERT( * val == chi2 );
  }
}
