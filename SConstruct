import SCons
from LocalConfig import GlobalVars

vars = Variables(None,ARGUMENTS);

# compilation flags
warningFlags = [ 
               ]

commonFlags =  [ 
               ] + warningFlags

if ARGUMENTS.get('config') == 'debug':
	commonFlags = ['-g'] + commonFlags
	
cFlags   = commonFlags

cxxFlags = commonFlags + [
           ]

vars.Add('config', 'Set to release or debug', 'release', allowed_values=('release', 'debug'))
vars.Add('tests', 'Set to build for tests', 0 , allowed_values=(0, 1))
buildEnv = Environment(	variables=vars,
					tools = ['mingw'],
					CFLAGS=cFlags,
					CXXFLAGS=cxxFlags,
					ENV = {'PATH' : GlobalVars['PYTHON_PATH']},
					NAME='mingw',
					OUTPUTDIR='Bin',
				  )
	
buildTestEnv = Environment(variables=vars,
							tools = ['mingw', ('cxxtest',{'CXXTEST' : GlobalVars['CXX_TEST_PATH']+'/bin/cxxtestgen'})],
							  toolpath=[GlobalVars['CXX_TEST_PATH']+'/build_tools/SCons/',GlobalVars['PYTHON_PATH']],
							  CFLAGS=cFlags,
							  CXXFLAGS=cxxFlags,
							  CPPPATH = [GlobalVars['GMOCK_PATH'] +'\include', GlobalVars['GMOCK_PATH'] +'\gtest\include'],
							  LIBPATH = [GlobalVars['GMOCK_PATH']],
							  LIBS = ['gmock'],
							  ENV = {'PATH' : GlobalVars['PYTHON_PATH']},
					          NAME='mingw',
					          OUTPUTDIR='Bin',
							  )
				  
if ARGUMENTS.get('tests') == '1':
	print 'build tests'
	SConscript('SConscript.test',exports={'env':buildTestEnv,'GlobalVars':GlobalVars})
else:
	print 'build lirary'
	SConscript('SConscript',exports={'env':buildEnv,'GlobalVars':GlobalVars})
