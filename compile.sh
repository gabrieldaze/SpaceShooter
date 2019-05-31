rm -rf build
mkdir build
cp -R assets build/assets
clang++ space_shooter.cpp -o build/spaceShooter -std=c++17 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
echo 'Space Shooter compiled successfuly'

