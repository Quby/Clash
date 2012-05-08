SConscript('SConstruct-Clash')

env = Environment()

libs = ['clash', 'sfml-system']

if env['PLATFORM'] == 'posix':
	env['LIBPATH']=['lib']
	env['CPPPATH']=['include']

conf = Configure(env)

for lib in libs:
	if not conf.CheckLib(lib):
		print lib + ' not found!';
		Exit(1)

env = conf.Finish()
env.Append(RPATH = 'lib')
env.Program(target = 'main', source = ['src/main.cpp'], LIBS=libs)
