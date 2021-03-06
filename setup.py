from setuptools import setup, Extension


setup(
    name='recurl',
    install_requires=['requests'],
    ext_modules=[
        Extension('recurl',
            sources=[
                'src/module.c', 'src/easyadapter.c', 'src/requests.c', 'src/util.c',
                'src/constants.c', 'src/curlwrap.c', 'src/exc.c',
            ],
            libraries=['curl'],
        ),
    ],
)

