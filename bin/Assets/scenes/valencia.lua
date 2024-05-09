local prefabs = {
	Paellera= {
		components = {
			Transform = {
				position = {0,-0.9,-11.4},
				scale = {1,1,1}
			},
			Mesh = {
				mesh = "paellera.mesh"			
			}
		}
	},
	iron-fence= {
		components = {
			Transform = {
				position = {-1.95,0.15,2.42},
				scale = {4,2.5,1}
			},
			Collider = {
				scale = {1, 0.83, 0.045}				
			}
		}
	}
}

local scenes = {
	SampleScene = {
		
		Plataformainicial= {
			components = {
				Transform= {
					position = {0,-0.6,0},
					scale = {8,1.5,4}
				},
				Collider = {				
				}
			}
		},
		Map1 = {
			components = {
				Transform= {
					position = {0,-0.6,-2.3},
					scale = {5.95,1.5,0.75}
				},
				Collider = {			
				}
			}
		},
		Map2 = {
			components = {
				Transform = {
					position = {0,-1.5,-7.5},
					scale = {9,0.3,11}
				},
				Collider = {				
				}
			}
		},
		Map3 = {
			components = {
				Transform= {
					position = {5.9,-1.5,-10.3},
					scale = {17,0.3,1}
				},
				Collider = {					
				}
			}
		},
		Map4 = {
			components = {
				Transform= {
					position = {-5.9,-1.5,-10.3},
					scale = {17,0.3,1}
				},
				Collide = { 					
				}
			}
		},
		Map5 = {
			components = {
				Transform= {
					position = {-4.7,-1.5,-9.7},
					scale = {1.25,0.3,9}
				},
				Collider = {				
				}
			}
		},
		Map6 = {
			components = {
				Transform= {
					position = {4.7,-1.5,-9.7},
					scale = {1.25,0.3,9}
				},
				Collider = {			
				}
			}
		},
		Map7 = {
			components = {
				Transform= {
					position = {-4.46,-0.6,-1.91},
					scale = {0.02,1.5,0.95}
				},
				Collider = {			
				}
			}
		},
		Map8 = {
			components = {
				Transform= {
					position = {4.46,-0.6,-1.91},
					scale = {0.02,1.5,0.95}
				},
				Collider = {			
				}
			}
		},

		Stairs = {
			blueprint = "Stairs",
			components = {
				Transform= {
					position = {-2.2,0,-2.8},
					rotation = {0,0.1736482,0,0.9848078},
					scale = {1,1,1}
				}
			},
			children = {
				Cube = {
					blueprint = "Cube",
					components = {
						Transform = {
							position = {0,0,0},
							scale = {2,0.3,1}
						},
						Collider = {						
						}
					}
				},
				Cube_1= {
					blueprint = "Cube_1",
					components = {
						Transform= {
							position = {0,-0.3,-0.5},
							scale = {2,0.3,2}
						},
						Collider = {						
						}
					}
				},
				Cube_2 = {
					blueprint = "Cube_2",
					components = {
						Transform = {
							position = {0,-0.6,-1},
							scale = {2,0.3,3}
						},
						Collider = {		
						}
					}
				},
				Cube_3= {
					blueprint = "Cube_3",
					components = {
						Transform= {
							position = {0,-0.9,-1.5},
							scale = {2,0.3,4}
						},
						Collider = {		
						}
					}
				},
				Cube_4= {
					blueprint = "Cube_4",
					components = {
						Transform = {
							position = {0,-1.2,-2},
							scale = {2,0.3,5}
						},
						Collider = {					
						}
					}
				}
			}
		},

		Stairs = {
			blueprint = "Stairs",
			components = {
				Transform= {
					position = {2.2,0,-2.8},
					rotation = {0,-0.1736483,0,0.9848078},
					scale = {1,1,1}
				}
			},
			children = {
				children = {
					Cube = {
						blueprint = "Cube",
						components = {
							Transform = {
								position = {0,0,0},
								scale = {2,0.3,1}
							},
							Collider = {						
							}
						}
					},
					Cube_1= {
						blueprint = "Cube_1",
						components = {
							Transform= {
								position = {0,-0.3,-0.5},
								scale = {2,0.3,2}
							},
							Collider = {						
							}
						}
					},
					Cube_2 = {
						blueprint = "Cube_2",
						components = {
							Transform = {
								position = {0,-0.6,-1},
								scale = {2,0.3,3}
							},
							Collider = {		
							}
						}
					},
					Cube_3= {
						blueprint = "Cube_3",
						components = {
							Transform= {
								position = {0,-0.9,-1.5},
								scale = {2,0.3,4}
							},
							Collider = {		
							}
						}
					},
					Cube_4= {
						blueprint = "Cube_4",
						components = {
							Transform = {
								position = {0,-1.2,-2},
								scale = {2,0.3,5}
							},
							Collider = {					
							}
						}
					}
				}
			}
		},

		Cylinder = {
			components = {
				Transform = {
					position = {0,-1.5,-18.6},
					rotation = {0,0,0,1},
					scale = {15.7,0.15,15.7}
				},
				Collider = {
					shapeType = cylinder					
				}
			}
		},

		Paellera1 = {
			blueprint = "Paellera",
			components = {
				Transform = {
					position = {0,-0.9,-11.4},
					rotation = {-0.2164395,0,0,0.9762961},
					scale = {1,1,1}
				}
			}
		},
		Paellera2 = {
			blueprint = "Paellera",
			components = {
				Transform = {
					position = {4,-1.2,-15},
					rotation = {0,-0.3007057,0,0.953717},
					scale = {1,1,1}
				}
			}
		},
		Paellera3 = {
			blueprint = "Paellera",
			components = {
				Transform = {
					position = {-4,-1.2,-15},
					rotation = {0,0.5372996,0,0.8433915},
					scale = {1,1,1}
				}
			}
		},

		Falla = {
			blueprint = "Falla",
			components = {
				Transform = {
					position = {0,-0.1,-22},
					rotation = {0,-0.7071068,0,0.7071068},
					scale = {1.25,1.25,1.25}
				}
			},
			children = {
				Cube = {
					blueprint = "Cube",
					components = {
						Transform = {
							position = {0,-0.75,0},
							scale = {2.15,0.5,4.15}
						},
						Collider = {					
						}
					}
				},
				Cube_1 = {
					blueprint = "Cube_1",
					components = {
						Transform = {
							position = {0,0,0},
							scale = {2,1,4}
						},
						Collider = {							
						}
					}
				},
				Statue= {
					blueprint = "Statue",
					components = {
						Transform = {
							position = {1,-0.4,-0.75},
							rotation = {0,0.7071068,0,0.7071068},
							scale = {35,35,35}
						},
						Mesh = {
							mesh = falla.mesh							
						}
					},
					children = {
						Mesh1= {
							blueprint = "Mesh1",
							components = {
								Transform= {
									position = {0,0,0},
									rotation = {0,0,0,1},
									scale = {1,1,1}
								}
							}
						}
					}
				}
			}
		},

		Vallas= {
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			children = {
				iron-fence19 = {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-1.95,0.15,2.42},
							rotation = {0,0,0,1},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence20 = {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {2.05,0.15,2.42},
							rotation = {0,0,0,1},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence21 = {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-4.43,0.15,-0.04},
							rotation = {0,-0.7071068,0,0.7071068},
							scale = {4,2.5,1}
						}
					}
				},
				
				iron-fence22 = {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {4.43,0.15,-0.04},
							rotation = {0,0.7071068,0,0.7071068},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence23= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-4.8,-1.35,-3.9},
							rotation = {0,-0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence24= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-5.494,-1.35,-7.84},
							rotation = {0,-0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence25= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-6.188,-1.35,-11.777},
							rotation = {0,-0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence26= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-6.877,-1.35,-15.712},
							rotation = {0,-0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence27= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-6.882,-1.35,-19.498},
							rotation = {0,-0.6427878,0,-0.7660443},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence28= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-5.461,-1.35,-22.928},
							rotation = {0,-0.4617489,0,-0.8870107},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence29= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {4.8,-1.35,-3.92},
							rotation = {0,0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence30= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {5.494,-1.35,-7.855},
							rotation = {0,0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence31= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {6.186,-1.35,-11.793},
							rotation = {0,0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence32= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {6.88,-1.35,-15.73},
							rotation = {0,0.7660445,0,-0.6427876},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence33= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {6.878,-1.35,-19.521},
							rotation = {0,0.6427877,0,-0.7660444},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence34= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {5.469,-1.35,-22.95},
							rotation = {0,0.4617488,0,-0.8870108},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence35= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {2.642,-1.35,-25.106},
							rotation = {0,0.1736485,0,-0.9848077},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence36= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {-2.664,-1.35,-25.079},
							rotation = {0,-0.1736483,0,-0.9848078},
							scale = {4,2.5,1}
						}
					}
				},
				iron-fence37= {
					blueprint = "iron-fence",
					components = {
						Transform= {
							position = {0,-1.35,-25.781},
							rotation = {0,0,0,1},
							scale = {4,2.5,1}
						}
					}
				}
			}
		},

		Grass = {
			components = {
				Transform= {
					position = {0,-1.55,-15},
					rotation = {0,0,0,1},
					scale = {7,7,7}
				},
				Collider= {
					scale = {10, 2.2, 10}					
				}
			}
		},

		End = {
			components = {
				Transform = {
					position = {0,-1.34,-19},
					rotation = {0,0,0,1},
					scale = {0.1,0.1,0.1}
				},
				Collider = {				
				}
			}
		},

		fountainRoundDetail= {
			components = {
				Transform= {
					position = {0,-1.35,-9},
					rotation = {0,0,0,1},
					scale = {2,2,2}
				},
				Collider= {
					shapeType = cylinder					
				},
				Mesh = {
					mesh = "fountain.mesh"
					material = "colormap"				
				}
			}
		}
	}	

return prefabs, scenes