// ----------------------------------------------------------------------------
//
// flxmlrpc Copyright (c) 2015 by W1HKJ, Dave Freese <iam_w1hkj@w1hkj.com>
//    
// XmlRpc++ Copyright (c) 2002-2008 by Chris Morley
//
// This file is part of fldigi
//
// flxmlrpc is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#ifndef _XMLRPCMUTEX_H_
#define _XMLRPCMUTEX_H_

#if defined(_MSC_VER)
# pragma warning(disable:4786)    // identifier was truncated in debug info
#endif

#include "threads.h"

namespace XmlRpc {

  //! A simple platform-independent mutex API implemented for posix and windows.
  class XmlRpcMutex {
  public:
    //! Construct a Mutex object.
    XmlRpcMutex() : _pMutex(0) {}

    //! Destroy a Mutex object.
    ~XmlRpcMutex();

    //! Wait for the mutex to be available and then acquire the lock.
    //! True return if acquired
    bool acquire();

    //! Release the mutex.
    void release();

    //! Utility class to acquire a mutex at construction and release it when destroyed.
    struct AutoLock {
      //! Acquire the mutex at construction
      AutoLock(XmlRpcMutex& m) : _m(m) { _m.acquire(); }
      //! Release at destruction
      ~AutoLock() { _m.release(); }
      //! The mutex being held
      XmlRpcMutex& _m;
    };

  private:

    //! Native Mutex object
    pthread_mutex_t* _pMutex;

  };  // class XmlRpcMutex

}  // namespace XmlRpc

#endif	//  _XMLRPCMUTEX_H_
