local blueprints = {

}

local scenes = {
    Test = {

        player = {
            handler = "Player",
                components = {
                    Transform = {
                        position = {0, 50, 0}
                    },
                    RigidBody = {
                        scale = {5, 5, 5},
                        mass = 0.01,
                        gravity = {0,0.01,0},
                        friction = 0,
                        restitution = 0,
                        shapeType = "Cube",
                        static = false,
                        layer = "ALL"
                    },
                    ShootComponent=0,
                    TestComponent=0
                }
        },
        cam = {
            handler = "cam",
            components = {
                Transform = {
                    position = {0, 50, 140}
                },
                Camera = {
                    nearClipDistance = 1,
                    autoAspectRatio = true,
                    backgroundColor = {0.6, 0.3, 0.3}
                },
                AudioListener = 0
            }
        },
        luz = {
            components = {
                Transform = {
                    position = {20, 80, 0}
                },
                Light = {
                    type = 0 
                }
            }
        }
    }
}

return blueprints, scenes