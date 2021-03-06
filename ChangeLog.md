Version 1.3.1
-------------
* Now requires Visual C++ Redistributable for Visual Studio 2015
* Added a build targetting .NET 4.0
* Internal reorganization of build process.
* Distributed as a NuGet package.

Version 1.3.0
---------------

* Moved source to GitHub, reorganized file structure of sources. 
* Removed support for any pre-vista operating system.
* Changed target .NET framework to 4.5
* Changed assembly name of platform specific dll's so they no longer include the version number since the same assembly can be used on all supported operating systems. (eg. AlphaVSS.x86.dll)

Version 1.2.4000.3
------------------
* BUG-18251: Fixed bug causing IVssBackupComponents.WriterStatus to incorrectly throw exception 
             stating that the operation is not supported on the current operating system on 
             Windows 2008 and Windows Vista.

Version 1.2.4000.2
------------------
* BUG-17860: All platfom-specific X86 assemblies were signed with the wrong public key and 
             failed to load.

Version 1.2.4000.1
------------------
* BREAKING CHANGE: The class VssWMFileDescription has been renamed to VssWMFileDescriptor

* BREAKING CHANGE: The IVssAsync interface has been removed. Any methods previously returning 
                   IVssAsync are now synchronous and returns void. Asynchronous versions of these
                   methods have been added with the standard APM naming scheme of BeginXXX, EndXXX
                   where the Begin method returns an IVssAsyncResult instance which implements
                   the standard IAsyncResult interface.

* The properties of IVssWMComponent that are not supported on earlier operating systems no longer 
  throw exceptions but return default values instead.

* A new sample application was added; AlphaShadow, which implements much of the same functionality as 
  the VShadow sample application from the Windows SDK.

* Delay signing has been removed and the public key of the assemblies has changed from the previous 
  version.

Version 1.2.3000
--------------
* Changed assembly naming of the platform specifiec assemblies so that their names 
  are the same regardless of the build configuration.

* Fixed invalid initialization VssBackupComponents of that caused potential memory issue 
  during finalization of this object (calling Release on IVssBackupComponentsEx and Ex2).

* Changed naming of the platform specific libraries, since the same library works on any 
  windows version >= Vista. They are now called AlphaVSS.XX.<platform>.dll for release 
  versions and AlphaVSS.XXd.<platform>.dll for debug versions where XX is 51 for XP, 
  52 for 2003 (and XP x64), and 60 for Vista and later windows versions.

* Removed feature configuration #defines in Config.h. Now uses ALPHAVSS_TARGET everywhere instead.

* The VssAsync interface now has a Wait-method accepting a timeout that is supported on 
  Windows Vista or later operating systems.

* Added new exception VssUnexpectedErrorException to represent the error codes E_UNEXPECTED
  and VSS_E_UNEXPECTED.

* Made most classes in AlphaVSS.Common serializable.

Version 1.0 beta
-------------------
* Erroneous Console.WriteLine printing the name of an assembly removed from 
  CreateBackupComponents. (How on earth did that get left in there anyway?)
  
* Many documentation updates.

* Some basic samples added.

* Assembly version mismatch solved.

* Bugfix: When detecting windows 2008, the VssUtils class returned 
  the string "2003", resulting in the wrong assembly being referenced by VssImplementation.

Version 1.0alpha
-------------------
* SetContext overload added to IVssBackupComponents accepting a 
  VssSnapshotContext enumeration value.
  
* New exception, UnsupportedOperatingSystemException added.

* VssSnapshotContext is now an enumeration.

* Support for methods from IVssExamineWriterMetadataEx and 
  IVssExamineWriterMetadataEx2 added to IVssExamineWriterMetadata.

* Support for methods from IVssBackupComponentsEx and IVssBackupComponentsEx2
  added to IVssBackupComponents.

* IVssSnapshotManagement and IDifferentialSoftwareSnapshotManagement interfaces and 
  classes added.

* VssWriterFailure enumeration removed, with new VssError enumeration containing
  all VSS error codes.

* Class OperatingSystemInfo added to AlphaVSS.Common, replacing old OSInfo 
  in AlphaVSS.Platform together with OSVersionName and ProcessorArchitecture 
  enumerations.

* Target-framework for AlphaVSS.Common changed to .NET 2.0.

* Binary release now has a Strong Name, also used during dynamic loading of 
  assemblies. Public key distributed with source.

* API documentation updated, all links now correct and documentation complete.

* Bug: IVssExamineWriterMetadata did not implement IDisposable, fixed.

* VssAsync, VssBackupComponents, VssComponent, VssExamineWriterMetadata, VssWMComponent 
  and VssWriterComponents have been made private classes and should instead be used through
  their corresponding interfaces, IVssAsync, IVssBackupComponents, IVssComponent, 
  IVssExamineWriterMetadata, IVssWMComponent and IVssWriterComponents.

* IsVolumeSnapshotted, GetSnapshotComatibility and ShouldBlockRevert moved from
  VssBackupComponents to (I)VssImplementation.
  
* IVssImplementation and VssUtils added to provide generic access to the implementation
  of VSS for the relevant platform.
    
* Order of parameters in IVssBackupComponents.AddToSnapshotSet() changed and an 
  additional overload provided.

* VssExamineWriterMetadata.Create() removed and replaced with 
  IVssImplementation.CreateVssExamineWriterMetadata().
  
* DeleteSnapshots replaced with DeleteSnapshot and DeleteSnapshotSet methods.

* Source folder structure changed

* Refactoring of assemblies, moving platform independent code out to 
  new assembly, AlphaVSS.Common.

* VssUnexpectedProviderError renamed to VssUnexpectedProviderErrorException

* VssUnexpectedWriterError renamed to VssUnexpectedWriterErrorException

* VssDifferencedFileInfo.FileSpec renamed to VssDifferencedFileInfo.FileSpecification

* Plus many things that probably didn't make it into this changelog...

Version 0.8 (alpha)
-------------------
* New build targets and dll-naming to support more versions 
  of windows (WinXP, Win2003, Vista, Win 2008, all in both x86 and x64 versions)
  
* DeleteSnapshots modified to remove out parameters and remove return of 
  error code. Errors now handled through exceptions.
  
* VssBackupComponents.Query was removed and replaced with the methods
  QuerySnapshots and QueryProviders. 

* VssSnapshotProp and VssProviderProp renamed and no longer implements the  
  IVssObjectProp interface which in turn was removed.
  
* Vss-prefix added to classes that previously did not have it.

* Multiple classes renamed to remove abbreviations, to follow the .NET 
  naming guidelines.
  
* ChangeLog.txt file added to keep track of changes between releases.
