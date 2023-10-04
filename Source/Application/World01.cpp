#include "World01.h"
#include "Framework/Framework.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

namespace nc
{
    float a = 1;
    float b = 0;

    bool World01::Initialize()
    {
        return true;
    }

    void World01::Shutdown()
    {
    }

    void World01::Update(float dt)
    {
        m_angle += 90 * dt;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_A) ? -dt : 0;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_D) ? dt : 0;
        if (ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_T))
        {
            m_time -= dt * 10; // Reverses Rotation when pressed
            
        }
        else if (ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_G)) {
            m_time += dt * 30; // Speeds up normal Rotation when pressed
        }
        else {
            m_time += dt * 10; // Base Rotation
        }

        if (ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_J)) { // Changes Colors to Yellow, Cyan, and Magenta
            a = 0;
            b = 1;
        }
        else { // Base Colors of Red, Blue, and Green
            a = 1;
            b = 0;
        }
    }

    void World01::Draw(Renderer& renderer)
    {
        // pre-render
        renderer.BeginFrame();

        // render
        glPushMatrix();
        glTranslatef(-0.5f, 0, 0);
        glRotatef(m_time, 0, 0, 1);
        glScalef(1,1,1);

        glBegin(GL_QUADS);

        glColor3f(a, b, b);
        glVertex2f(-0.5f, -0.5f);

        glColor3f(a, b, a);
        glVertex2f(-0.5f, 0.5f);

        glColor3f(b, b, a);
        glVertex2f(0.5f, 0.5f);

        glColor3f(b, a, b);
        glVertex2f(0.5f, -0.5f);
        //std::cout << "Hello!" << std::endl;
        glEnd();

        glPopMatrix();
        
        // post-render
        renderer.EndFrame();
    }
}
