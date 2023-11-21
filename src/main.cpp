#include <sil/sil.hpp>
#include <random.hpp>
#include <iostream>

void vert(sil::Image& image)
{
    // TODO: modifier l'image
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }

    image.save("output/pouet.png");
}

void canaux(sil::Image& image)
{
    // TODO: modifier l'image
    for (glm::vec3& color : image.pixels())
    {
        float temp;
        temp = color.r;
        color.r = color.b;
        color.b = temp;
    }

    image.save("output/pouet.png");
}

void noir_blanc(sil::Image& image)
{
    // TODO: modifier l'image
    for (glm::vec3& color : image.pixels())
    {
        float average = (color.r + color.g + color.b)/3;
        color.r = average;
        color.g = average;
        color.b = average;
    }

    image.save("output/pouet.png");
}

void negatif(sil::Image& image)
{
    // TODO: modifier l'image
    for (glm::vec3& color : image.pixels())
    {
        color.r = 1.0f - color.r;
        color.g = 1.0f - color.g;
        color.b = 1.0f - color.b;
    }

    image.save("output/pouet.png");
}

void degrade(sil::Image& image)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = static_cast<float>(x) / image.width();
            image.pixel(x, y).g = static_cast<float>(x) / image.width();
            image.pixel(x, y).b = static_cast<float>(x) / image.width();
        }
    }

    image.save("output/pouet.png");
}

void miroir(sil::Image& image, sil::Image copie)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = copie.pixel(copie.width() - (x+1), y);
        }
    }

    image.save("output/pouet.png");
}

void bruit(sil::Image& image)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            int randInt = random_int(0, 8);
            float randColor{.0f};
            
            if(randInt < 2)
            {
                randColor = random_float(.0f, 1.0f);
                image.pixel(x, y).r = randColor;
                randColor = random_float(.0f, 1.0f);
                image.pixel(x, y).g = randColor;
                randColor = random_float(.0f, 1.0f);
                image.pixel(x, y).b = randColor;
            }
        }
    }

    image.save("output/pouet.png");
}

void rotation(sil::Image& image, sil::Image& copie)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = copie.pixel(y, copie.height()-x-1);
        }
    }

    image.save("output/pouet.png");
}

void rgbSplit(sil::Image& image, sil::Image copie)
{
    // TODO: modifier l'image
    for(int x{20}; x < image.width() - 20; x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = copie.pixel(x-20, y).r;
            image.pixel(x, y).g = copie.pixel(x, y).g;
            image.pixel(x, y).b = copie.pixel(x+20, y).b;
        }
    }

    image.save("output/pouet.png");
}

void eclaircissement(sil::Image& image)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = std::pow(image.pixel(x, y).r, .5f);
            image.pixel(x, y).g = std::pow(image.pixel(x, y).g, .5f);
            image.pixel(x, y).b = std::pow(image.pixel(x, y).b, .5f);
        }
    }

    image.save("output/pouet.png");
}

void assombrissement(sil::Image& image)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = std::pow(image.pixel(x, y).r, 2.0f);
            image.pixel(x, y).g = std::pow(image.pixel(x, y).g, 2.0f);
            image.pixel(x, y).b = std::pow(image.pixel(x, y).b, 2.0f);
        }
    }

    image.save("output/pouet.png");
}

void disque(sil::Image& image)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            if(std::pow(x-(image.width()/2), 2.0f) + std::pow(y-(image.width()/2), 2.0f) < std::pow(100.0f, 2.0f))
            {
                image.pixel(x, y).r = 1.0f;
                image.pixel(x, y).g = 1.0f;
                image.pixel(x, y).b = 1.0f;
            }
        }
    }

    image.save("output/pouet.png");
}

void cercle(sil::Image& image)
{
    float radius = 100.0f;
    float thickness = 10.0f;

    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            if(std::pow(x-(image.width()/2), 2.0f) + std::pow(y-(image.width()/2), 2.0f) < std::pow(radius, 2.0f)
            && std::pow(x-(image.width()/2), 2.0f) + std::pow(y-(image.width()/2), 2.0f) > std::pow(radius-thickness, 2.0f))
            {
                image.pixel(x, y).r = 1.0f;
                image.pixel(x, y).g = 1.0f;
                image.pixel(x, y).b = 1.0f;
            }
        }
    }

    image.save("output/pouet.png");
}

void rosace(sil::Image& image)
{
    float radius = 100.0f;
    float thickness = 5.0f;

    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            if(std::pow(x-(image.width()/2), 2.0f) + std::pow(y-(image.width()/2), 2.0f) < std::pow(radius, 2.0f)
            && std::pow(x-(image.width()/2), 2.0f) + std::pow(y-(image.width()/2), 2.0f) > std::pow(radius-thickness, 2.0f))
            {
                image.pixel(x, y).r = 1.0f;
                image.pixel(x, y).g = 1.0f;
                image.pixel(x, y).b = 1.0f;
            }

            for (size_t i = 60; i <= 360; i += 60)
            {
                if(std::pow(x-(image.width()/2)+radius*std::cos(i*std::acos(-1)/180), 2.0f) + std::pow(y-(image.width()/2)+radius*std::sin(i*std::acos(-1)/180), 2.0f) < std::pow(radius, 2.0f)
                && std::pow(x-(image.width()/2)+radius*std::cos(i*std::acos(-1)/180), 2.0f) + std::pow(y-(image.width()/2)+radius*std::sin(i*std::acos(-1)/180), 2.0f) > std::pow(radius-thickness, 2.0f))
                {
                    image.pixel(x, y).r = 1.0f;
                    image.pixel(x, y).g = 1.0f;
                    image.pixel(x, y).b = 1.0f;
                }
            }
        }
    }

    image.save("output/pouet.png");
}

void mosaique(sil::Image& image, sil::Image copie)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            for (int i{0}; i < 5; i++)
            {
                for (int j{0}; j < 5; j++)
                {
                    image.pixel(x/5+(image.width()/5*i), y/5+(image.height()/5*j)) = copie.pixel(x, y);
                }                
            }
        }
    }

    image.save("output/pouet.png");
}

void mosaiqueMiroir(sil::Image& image, sil::Image copie)
{
    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            for (int i{0}; i < 5; i++)
            {
                for (int j{0}; j < 5; j++)
                {                    
                    if(j%2 == 1 && i%2 == 1)
                    {
                        image.pixel(x/5+(image.width()/5*i), y/5+(image.height()/5*j)) = copie.pixel(copie.width()-x-1, copie.height()-y-1);
                    }
                    else if(j%2 == 1)
                    {
                        image.pixel(x/5+(image.width()/5*i), y/5+(image.height()/5*j)) = copie.pixel(x, copie.height()-y-1);
                    }
                    else if(j%2 == 0)
                    {
                        if(i%2 == 1)
                            image.pixel(x/5+(image.width()/5*i), y/5+(image.height()/5*j)) = copie.pixel(copie.width()-x-1, y);
                        else
                            image.pixel(x/5+(image.width()/5*i), y/5+(image.height()/5*j)) = copie.pixel(x, y);
                    }
                }                
            }
        }
    }

    image.save("output/pouet.png");
}

int main()
{
    set_random_seed(0);

    sil::Image image{"images/logo.png"};
    sil::Image imageNoire{300, 200};
    sil::Image imageTournee{image.height(), image.width()};
    sil::Image image2{"images/photo.jpg"};
    sil::Image imageDisque{500, 500};
    // vert(image);
    // canaux(image);
    // noir_blanc(image);
    // negatif(image);
    // degrade(imageNoire);
    // miroir(image, image);
    // bruit(image);
    // rotation(imageTournee, image);
    // rgbSplit(image, image);
    // eclaircissement(image2);
    // assombrissement(image2);
    // disque(imageDisque);
    // cercle(imageDisque);
    // rosace(imageDisque);
    // mosaique(image, image);
    mosaiqueMiroir(image, image);
}