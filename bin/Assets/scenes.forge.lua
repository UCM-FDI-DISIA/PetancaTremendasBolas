local prefabs = {
    ball = {
        handler = "ball",
            components = {
                Transform = {
                    position = {0, 50, 0}
                },
                RigidBody = {
                    scale = {5, 5, 5},
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
                    friction = 0.5,
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
                        position = {0, -10, 0}
                    },
                    RigidBody= {
                        scale = {500,10,500},
                        static = true
                    },
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