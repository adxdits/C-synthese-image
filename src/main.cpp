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

void rotation(sil::Image& image)
{
    sil::Image rotatedImage{image.height(), image.width()};
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            rotatedImage.pixel(y, rotatedImage.height() - 1 - x) = image.pixel(x, y);
        }
    }
    image = rotatedImage;
    image.save("output/pouet_rotated.png");
}

void rgbSplit(sil::Image& image)
{
    sil::Image tempImage{image}; 

    for (int x = 0; x < image.width(); ++x) {
        for (int y = 0; y < image.height(); ++y) {
            glm::vec3 color = tempImage.pixel(x, y);
            int nRed = x + 10;
            int nGreen = y + 10;
            int nBlue = x + 10;
            nRed = std::max(0, std::min(image.width() - 1, nRed));
            nGreen = std::max(0, std::min(image.height() - 1, nGreen));
            nBlue = std::max(0, std::min(image.width() - 1, nBlue));

         
            image.pixel(nRed, y).r = color.r; 
            image.pixel(x, nGreen).g = color.g; 
            image.pixel(nBlue, y).b = color.b; 
        }
    }

    image.save("output/r.png");
}

void lum(sil::Image& image)
{
    for (int x = 0; x < image.width(); ++x) {
        for (int y = 0; y < image.height(); ++y) {
            glm::vec3& color = image.pixel(x, y);

           
            color.r *= 109;
            color.g *= 100;
            color.b *= 100;
        image.save("output/lum.png");
} } }

void circle() {
    const int width = 300;
    const int height = 300;

    sil::Image image(width, height);
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f); 
            int centerX = width / 2;
            int centerY = height / 2;
            int radius = 100;
            if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) {
                color = glm::vec3(1.0f, 1.0f, 1.0f); 
            }
            image.pixel(x, y).r = color.r;
            image.pixel(x, y).g = color.g;
            image.pixel(x, y).b = color.b;
        }
    }
    image.save("output/cerc.png");
}

int main()
{
    set_random_seed(0);

    sil::Image image{"images/logo.png"};
    sil::Image imageNoire{300, 200};
    // vert(image);
    // canaux(image);
    // noir_blanc(image);
    // negatif(image);
    // degrade(imageNoire);
    // miroir(image, image);
    //bruit(image);
    //rotation(image);
    //LEGLITCH(image);
    //lum(image);
    circle();
    image.save("output/cerc.png");
}
