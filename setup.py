from setuptools import setup, Extension

module = Extension(
    "filterparser",
    sources=[
        "src/library.c",
        "src/struct.c",
    ],
    include_dirs=["src", ]
)

setup(
    name="FilterParser",
    version="0.1.0",
    author="Georgii Imeshkenov",
    description="nd",
    ext_modules=[module],
)
