/* Copyright (c) 2008-2011 Peter Palotas
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#include <StdAfx.h>
#include "VssAsync.h"

namespace Alphaleonis { namespace Win32 { namespace Vss
{
   [System::Security::Permissions::SecurityPermissionAttribute(System::Security::Permissions::SecurityAction::LinkDemand)]
   VssAsync^ VssAsync::Adopt(::IVssAsync *vssAsync)
   {
      try
      {
         return gcnew VssAsync(vssAsync);
      }
      catch (...)
      {
         vssAsync->Release();
         throw;
      }
   }

   VssAsync::VssAsync(::IVssAsync *vssAsync)
      : m_vssAsync(vssAsync)
   {
   }

   VssAsync::~VssAsync()
   {
      this->!VssAsync();
   }

   VssAsync::!VssAsync()
   {
      if (m_vssAsync != 0)
      {
         m_vssAsync->Release();
         m_vssAsync = 0;
      }
   }

   VssError VssAsync::Cancel()
   {
      HRESULT hrResult = 0;
      hrResult = m_vssAsync->Cancel();
      if (FAILED(hrResult))
         ThrowException(hrResult);
      return (VssError)hrResult;
   }

   VssError VssAsync::QueryStatus()
   {
      HRESULT hrResult = 0;
      CheckCom(m_vssAsync->QueryStatus(&hrResult, 0));
      return (VssError)hrResult;
   }
   
   void VssAsync::Wait()
   {
#if ALPHAVSS_TARGET >= ALPHAVSS_TARGET_WIN2003
      CheckCom(m_vssAsync->Wait(INFINITE));
#else
      CheckCom(m_vssAsync->Wait());
#endif
   }


   void VssAsync::Wait(Int32 timeoutMilliseconds)
   {
#if ALPHAVSS_TARGET < ALPHAVSS_TARGET_WINVISTAORLATER
      Wait();
#else
      CheckCom(m_vssAsync->Wait(timeoutMilliseconds));
#endif
   }


}
} }