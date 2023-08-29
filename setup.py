from setuptools import setup, Extension

module = Extension(
    "filterparser",
    sources=["library.c", "struct.c", ]
)

setup(
    name="FilterParser",
    version="0.1.0",
    description="nd",
    ext_modules=[module]
)
