clang++ space_shooter.cpp -o spaceShooter -std=c++17 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

rm -rf build
mkdir build
mkdir build/raw
cp -R assets build/raw/assets
cp spaceShooter build/raw/spaceShooter

mkdir build/executable
mkdir build/executable/SpaceShooter.app
mkdir build/executable/SpaceShooter.app/Contents
mkdir build/executable/SpaceShooter.app/Contents/MacOS
mkdir build/executable/SpaceShooter.app/Contents/Resources

cp Info.plist build/executable/SpaceShooter.app/Contents/Info.plist
cp -R assets build/executable/SpaceShooter.app/Contents/Resources/assets
cp spaceShooter build/executable/SpaceShooter.app/Contents/MacOS/spaceShooter

rm -f spaceShooter

echo 'Space Shooter compiled successfuly'