#include <sil/sil.hpp>
#include <random.hpp>
#include <iostream>
#include <glm/gtx/matrix_transform_2d.hpp>

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

void glitch(sil::Image& image, sil::Image copie)
{   
    // TODO: modifier l'image
    for (int i{0}; i < 200; i++)
    {
        int randX = random_int(0, copie.width()-30);
        int randWidth = random_int(10, 40);

        int randY = random_int(0, copie.height()-5);
        int randHeight = random_int(1, 6);

        int randCopieX = random_int(0, copie.width()-30);
        int randCopieY = random_int(0, copie.height()-5);

        for(int x{randX}; x < randX+randWidth; x++)
        {
            for(int y{randY}; y < randY+randHeight; y++)
            {
                image.pixel(x, y) = copie.pixel(randCopieX, randCopieY);
            }
        }   
    }

    image.save("output/pouet.png");
}

void fractale(sil::Image& image)
{   
    float c{0};
    int itMax{18};
    float color{.5f};

    // TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            float c_r = x*4/static_cast<float>(image.width())-2.0f;
            float c_i = y*4/static_cast<float>(image.height())-2.0f;
            float z_r{0};
            float z_i{0};
            int i{0};

            color = .0f;

            while(z_r*z_r + z_i*z_i < 4 && i < itMax)
            {
                float tmp = z_r;
                z_r = z_r*z_r - z_i*z_i + c_r;
                z_i = 2*z_i*tmp + c_i;
                i++;
            }

            if(i == itMax)
            {
                image.pixel(x, y) = {1.0f, 1.0f, 1.0f};
            }
            else
            {
                if(color < 1.0f)
                    color += .035f*static_cast<float>(i);

                image.pixel(x, y) = {.0f + color, .0f + color, .0f + color};
            }
        }
    }

    image.save("output/pouet.png");
}

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

void vortex(sil::Image& image, sil::Image copie)
{   
    int copieX{0};
    int copieY{0};

    //TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            int dist = sqrt(std::pow(x-copie.width()/2.0f, 2) + std::pow(y-copie.height()/2.0f, 2));

            glm::vec2 rotatedPixel = rotated({x, y}, {image.width()/2.0f, image.height()/2.0f}, std::acos(-1)*dist/180.0f*5.0f);

            if(rotatedPixel.x < image.width() && rotatedPixel.y < image.height()
            && rotatedPixel.x > 0             && rotatedPixel.y > 0)
            {
                copieX = rotatedPixel.x;
                copieY = rotatedPixel.y;

                image.pixel(x, y) = copie.pixel(copieX, copieY);
            }
        }
    }

    image.save("output/pouet.png");
}

void tramage(sil::Image& image)
{       
    const int bayer_n = 4;
    float bayer_matrix_4x4[][bayer_n] = {
    {    -0.5,       0,  -0.375,   0.125 },
    {    0.25,   -0.25,   0.375, - 0.125 },
    { -0.3125,  0.1875, -0.4375,  0.0625 },
    {  0.4375, -0.0625,  0.3125, -0.1875 },
    };

    //TODO: modifier l'image
    for(int x{0}; x < image.width(); x++)
    {
        for(int y{0}; y < image.height(); y++)
        {
            if(image.pixel(x, y).r + bayer_matrix_4x4[x%4][y%4] <= .5f)
            {
                image.pixel(x, y) = {.0f, .0f, .0f};
            }
            else
            {
                image.pixel(x, y) = {1.0f, 1.0f, 1.0f};
            }
        }
    }

    image.save("output/pouet.png");
}

int main()
{
    set_random_seed(0);

    sil::Image image{"images/logo.png"};
    sil::Image imageNoireLogo{image.width(), image.height()};
    sil::Image imageNoire{300, 200};
    sil::Image imageTournee{image.height(), image.width()};
    sil::Image image2{"images/photo.jpg"};
    sil::Image imageCarree{500, 500};
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
    // disque(imageCarree);
    // cercle(imageCarree);
    // rosace(imageCarree);
    // mosaique(image, image);
    // mosaiqueMiroir(image, image);
    // glitch(image, image);
    // fractale(imageCarree);
    // vortex(imageNoireLogo, image);
    tramage(image2);
}