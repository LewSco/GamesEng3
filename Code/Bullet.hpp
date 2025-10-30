//Bullet.hpp
#include<SFML/Graphics.hpp>

using namespace sf;

class Bullet : public Sprite 
{
    public:

        //updates all bullets (by calling _Update() on all bullets in the pool)
        static void Update(const float& dt);

        //Render's all bullets (uses a similar trick to the ship renderer but on the bullet pool)
        static void Render(RenderWindow& window);

        //Chose an inactive bullet and use it.
        static void Fire(const Vector2f& pos, const bool mode);

        //Set all the bullets to -100, -100, set the spritesheet, set origin
        static void Init();

        ~Bullet() = default;

    protected:

        Bullet();

        //true=player bullet, false=Enemy bullet
        bool _mode;

        //Called by the static Update()
        void _Update(const float& dt);

        static unsigned char _bulletPointer;

        static Bullet _bullets[256];
};