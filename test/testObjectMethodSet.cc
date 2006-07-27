// $Id: testObjectMethodSet.cpp,v 1.1 2006/06/20 14:54:25 llista Exp $
#include <cppunit/extensions/HelperMacros.h>
#include "PhysicsTools/UtilAlgos/interface/ObjectMethodSet.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include <Reflex/Object.h>
#include <iostream>

class testObjectMethodSet : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(testObjectMethodSet);
  CPPUNIT_TEST(checkAll);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() {}
  void tearDown() {}
  void checkAll(); 
};

CPPUNIT_TEST_SUITE_REGISTRATION(testObjectMethodSet);

void testObjectMethodSet::checkAll() {
  using namespace ROOT::Reflex;
  typedef reco::ObjectMethodSet<reco::Track> TrackMethodSet; 
  const TrackMethodSet::methodMap & m = TrackMethodSet::methods();
  //  TrackMethodSet::print( std::cerr );

  double chi2 = 1.234;
  double ndof = 2.345;
  double pt = 10.0;
  math::Vector<5>::type par( 1.0, 2.0, 3.0, 4.0, 5.0 );
  math::Error<5>::type err;
  reco::Track trk( chi2, ndof, par, pt, err );
  Type trackType = Type::ByTypeInfo( typeid( reco::Track ) );
  Object trko( trackType, & trk );

  {
    TrackMethodSet::methodMap::const_iterator f = m.find( "pt" );
    CPPUNIT_ASSERT( f != m.end() );
    Object ret = f->second.Invoke( trko );
    double * val = static_cast<double *>( ret.Address() );
    CPPUNIT_ASSERT( * val == pt );
  }
  {
    TrackMethodSet::methodMap::const_iterator f = m.find( "chi2" );
    CPPUNIT_ASSERT( f != m.end() );
    Object ret = f->second.Invoke( trko );
    double * val = static_cast<double *>( ret.Address() );
    CPPUNIT_ASSERT( * val == chi2 );
  }
}
