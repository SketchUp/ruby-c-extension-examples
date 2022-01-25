project_path = File.expand_path('..', __dir__)

ruby_version = ARGV[0]
raise 'Missing version argument' if ruby_version.nil? || ruby_version.empty?

target_basepath = "Debug (#{ruby_version})"

bundle_name = 'SUEX_HelloWorld.bundle'

filepath = File.join(project_path, target_basepath, bundle_name)

puts filepath
data = File.open(filepath, 'rb') { |file| file.read }
results = data.scan(/[a-zA-Z0-9\-_]*darwin[a-zA-Z0-9\-_]*/)

results.each { |result|
  puts result
}