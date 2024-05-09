local prefabs = {
    ball = {
        handler = "ball",
            components = {
                Transform = {
                    position = {0, 50, 0},
                    scale = {5, 5, 5}
                },
                RigidBody = {
                    mass = 0.01,
                    gravity = {0,-9.8,0},
                    friction = 1,
                    restitution = 0,
                    shapeType = "Sphere",
                    static = false,
                    layer = "ALL", 
                    trigger = false
                },
                ShootComponent = {
                    maxForce=500
                },
                Mesh={
                    mesh ="Bola.mesh",
                    material= "MatPePa"
                 }
        }
    },
    
    boliche = {
        handler = "boliche",
            components = {
                Transform = {
                    position = {0, 50, 0}
                 },
                RigidBody = {
                     scale = {2, 2, 2},
                     mass = 0.005,
                    gravity = {0,-9.8,0},
                    friction = 1,
                    restitution = 0,
                    shapeType = "Sphere",
                    static = false,
                    layer = "ALL", 
                    trigger = false
                },
                ShootComponent = {
                    maxForce=100
                }
            }
        }
}

local scenes = {
    Test = {
        GameManager = {
            handler = "GameManager",
                components = {
                    GameManager = 0
                }
        },
        suelo = {
            handler = "Suelo",
                components = {
                    Transform = {
                        position = {0, -10, 0},
                        scale = {200,10,200}
                    },
                    RigidBody= {
                        friction=1,
                        static = true
                    },
                    Mesh={
                        mesh ="sphere.mesh",
                     }
                }
        },
        cam = {
            handler = "cam",
            components = {
                Transform = {
                    position = {0, 50, 250}
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

return prefabs, scenes