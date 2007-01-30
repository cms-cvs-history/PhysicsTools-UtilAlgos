#ifndef UtilAlgos_TFileService_h
#define UtilAlgos_TFileService_h
/* \class TFileService
 *
 * \author Luca Lista, INFN
 *
 */
#include <string>

class TFile;

namespace edm {
  class ActivityRegistry;
  class ParameterSet;
  class ModuleDescription;
}


class TFileService {
public:
  /// constructor
  TFileService( const edm::ParameterSet &, edm::ActivityRegistry & );
  /// destructor
  ~TFileService();
  /// return opened TFile
  TFile & file() const { return * file_; } 
  /// make new ROOT object
  template<typename T>
  T * make() const {
    cd(); return new T();
  }
  /// make new ROOT object
  template<typename T, typename Arg1>
  T * make( const Arg1 & a1 ) const {
    cd(); return new T( a1 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2>
  T * make( const Arg1 & a1, const Arg2 & a2 ) const {
    cd(); return new T( a1, a2 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3 ) const {
    cd(); return new T( a1, a2, a3 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4 ) const {
    cd(); return new T( a1, a2, a3, a4 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5 ) const {
    cd(); return new T( a1, a2, a3, a4, a5 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5, typename Arg6>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5, const Arg6 & a6 ) const {
    cd(); return new T( a1, a2, a3, a4, a5, a6 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5, typename Arg6, typename Arg7>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5, const Arg6 & a6, const Arg7 & a7 ) const {
    cd(); return new T( a1, a2, a3, a4, a5, a6, a7 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5, typename Arg6, typename Arg7, typename Arg8>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5, const Arg6 & a6, const Arg7 & a7, const Arg8 & a8 ) const {
    cd(); return new T( a1, a2, a3, a4, a5, a6, a7, a8 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5, typename Arg6, typename Arg7, typename Arg8, 
	   typename Arg9>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5, const Arg6 & a6, const Arg7 & a7, const Arg8 & a8,
	    const Arg9 & a9 ) const {
    cd(); return new T( a1, a2, a3, a4, a5, a6, a7, a8, a9 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5, typename Arg6, typename Arg7, typename Arg8, 
	   typename Arg9, typename Arg10>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5, const Arg6 & a6, const Arg7 & a7, const Arg8 & a8,
	    const Arg9 & a9, const Arg10 & a10 ) const {
    cd(); return new T( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5, typename Arg6, typename Arg7, typename Arg8, 
	   typename Arg9, typename Arg10, typename Arg11>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5, const Arg6 & a6, const Arg7 & a7, const Arg8 & a8,
	    const Arg9 & a9, const Arg10 & a10, const Arg11 & a11 ) const {
    cd(); return new T( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11 );
  }
  /// make new ROOT object
  template<typename T, typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
	   typename Arg5, typename Arg6, typename Arg7, typename Arg8, 
	   typename Arg9, typename Arg10, typename Arg11, typename Arg12>
  T * make( const Arg1 & a1, const Arg2 & a2, const Arg3 & a3, const Arg4 & a4, 
	    const Arg5 & a5, const Arg6 & a6, const Arg7 & a7, const Arg8 & a8,
	    const Arg9 & a9, const Arg10 & a10, const Arg11 & a11, const Arg12 & a12 ) const {
    cd(); return new T( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12 );
  }

private:
  /// pointer to opened TFile
  TFile * file_;
  // set current directory according to module name and prepair to create directory
  void setDirectoryName( const edm::ModuleDescription & desc );
  // current module label
  std::string currentModuleLabel_, currentModulenName_;
  /// change (and possibly create) to current directory
  void cd() const;
};

#endif
