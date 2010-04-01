#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 822;
	static const long REVISION = 4665;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 915;
	#define RC_FILEVERSION 0,9,822,4665
	#define RC_FILEVERSION_STRING "0, 9, 822, 4665\0"
	static const char FULLVERSION_STRING[] = "0.9.822.4665";
	
	//SVN Version
	static const char SVN_REVISION[] = "204";
	static const char SVN_DATE[] = "2010-03-29T00:41:26.273896Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 30;
	

}
#endif //VERSION_h
