#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 880;
	static const long REVISION = 4973;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 980;
	#define RC_FILEVERSION 0,9,880,4973
	#define RC_FILEVERSION_STRING "0, 9, 880, 4973\0"
	static const char FULLVERSION_STRING[] = "0.9.880.4973";
	
	//SVN Version
	static const char SVN_REVISION[] = "208";
	static const char SVN_DATE[] = "2010-04-01T01:31:59.387749Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 58;
	

}
#endif //VERSION_h
