from setuptools import setup
import glob
import os

package_name = 'training1_turtlesim'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob.glob(os.path.join('launch', '*.launch.py'))),
        ('share/' + package_name + '/param', glob.glob(os.path.join('param', '*.yaml'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dongri',
    maintainer_email='dongri@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'SubPub = training1_turtlesim.SubPub:main',
        ],
    },
)
