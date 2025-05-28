using Images , FileIO , Printf

function make_gif(folder::String , size::Int , gens::Int , gen0::Int , fileName::String)
    frames = []

    count = 0

    println("Size: " , size)
    println("# of generations: " , gens)
    println("Initial generation: " , gen0)

    print("[")

    for i in gen0:gens
        path = joinpath(folder , @sprintf("frame%d.bin" , i))
        raw  = read(path)

        grid = reshape(raw , size , size)'

        push!(frames , colorview(Gray , Float32.(grid)))

        if(i*100 // gens > count)
            print("=")
            flush(stdout)
            count += 5
        end
    end

    print("]\n")

    save(fileName , cat(frames... , dims = 3))
end

function main()
    # Get the size of the lactice and the number of generations
    gens , size , gen0 = open("INPUT.dat") do io
        init_gen = parse(Bool , readline(io))
        x = parse(Int , readline(io))
        y = -1
        z = 0
        if init_gen
            file_name = "save/config.dat"
            if !isfile(file_name)
                file_name = ".bckup/initial.dat"
            end
            appo = open(file_name) do fin
                return split(readline(fin))
            end
            y = parse(Int , appo[1])
            z = parse(Int , appo[3])
        else
            readline(io)
            y = parse(Int , readline(io))
        end

        @assert (y > 0) "Not valid size"

        x += z

        return x , y , z
    end

    make_gif("data" , size , gens , gen0 ,  "life.gif")
end

main()
