
/****************************************************************************** 
 * 
 *  file:  CmdLineInterface.h
 * 
 *  Copyright (c) 2003, Michael E. Smoot .
 *  Copyright (c) 2004, Michael E. Smoot, Daniel Aarno.
 *  All rights reverved.
 *
 *  See the file COPYING in the top directory of this distribution for
 *  more information.
 *  
 *  THE SOFTWARE IS PROVIDED _AS IS_, WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 *  DEALINGS IN THE SOFTWARE.  
 *  
 *****************************************************************************/ 

#ifndef TCLAP_COMMANDLINE_INTERFACE_H
#define TCLAP_COMMANDLINE_INTERFACE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>


namespace TCLAP {
     
class Arg;
class CmdLineOutput;
class XorHandler;

/**
 * The base class that manages the command line definition and passes
 * along the parsing to the appropriate Arg classes.
 */
class CmdLineInterface
{
	public:

		/**
		 * Destructor
		 */
		virtual ~CmdLineInterface() {}

		/**
		 * Adds an argument to the list of arguments to be parsed.
		 * \param a - Argument to be added. 
		 */
		virtual void add( Arg& a )=0;

		/**
		 * An alternative add.  Functionally identical.
		 * \param a - Argument to be added. 
		 */
		virtual void add( Arg* a )=0;

		/**
		 * Add two Args that will be xor'd.  
		 * If this method is used, add does
		 * not need to be called.
		 * \param a - Argument to be added and xor'd. 
		 * \param b - Argument to be added and xor'd. 
		 */
		virtual void xorAdd( Arg& a, Arg& b )=0;

		/**
		 * Add a list of Args that will be xor'd.  If this method is used, 
		 * add does not need to be called.
		 * \param xors - List of Args to be added and xor'd. 
		 */
		virtual void xorAdd( std::vector<Arg*>& xors )=0;

		/**
		 * Parses the command line.
		 * \param argc - Number of arguments.
		 * \param argv - Array of arguments.
		 * \param bExit - If true, the program exits when an Arg Exception is thrown.
		 */
		virtual void parse(int argc, TCHAR ** argv, bool bExit)=0;

		/**
		 * Returns the CmdLineOutput object.
		 */
		virtual CmdLineOutput* getOutput()=0;

		/**
		 * \param co - CmdLineOutput object that we want to use instead. 
		 */
		virtual void setOutput(CmdLineOutput* co)=0;

		/**
		 * Returns the version wstring.
		 */
		virtual std::wstring& getVersion()=0;

		/**
		 * Returns the program name wstring.
		 */
		virtual std::wstring& getProgramName()=0;

		/**
		 * Returns the argList. 
		 */
		virtual std::list<Arg*>& getArgList()=0;

		/**
		 * Returns the XorHandler. 
		 */
		virtual XorHandler& getXorHandler()=0;

		/**
		 * Returns the delimiter wstring.
		 */
		virtual TCHAR getDelimiter()=0;

		/**
		 * Returns the message wstring.
		 */
		virtual std::wstring& getMessage()=0;

		/**
		 * Indicates whether or not the help and version switches were created
		 * automatically.
		 */
		virtual bool hasHelpAndVersion()=0;
};

} //namespace


#endif 
