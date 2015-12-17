moduleName = 'MyLib'

Import('env', 'GlobalVars')
buildEnv = env.Clone()

sourceDir = 'Library/Src'
buildDir='build\\%s-%s\\%s' %(buildEnv['NAME'],buildEnv['CCVERSION'], sourceDir)

buildEnv.VariantDir(buildDir,sourceDir,duplicate=0)
srcFiles = [Glob(buildDir+'/*.cpp')]

usedModules = [
    ]

localIncludePaths = [
	'include',
    ] 

library_include_path = Dir(localIncludePaths)
buildEnv.Append(CPPPATH = library_include_path)   

library=buildEnv.StaticLibrary('%s/%s/%s' % (buildEnv['OUTPUTDIR'],buildEnv['config'],moduleName),srcFiles)
Return ('library','library_include_path')
